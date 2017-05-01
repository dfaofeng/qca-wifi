/*
 * Copyright (c) 2010, Atheros Communications Inc. 
 * All Rights Reserved.
 * 
 * Copyright (c) 2011 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 * 
 */

//----------------------------------------------------------------------------
//
//  Project:   BT3_CORE
//
//  Filename:  pal_osapi.c
//
//  Author:    Zhihua Liu
//
//  Created:   04/16/2009
//
//  Descriptions:
//
//    PAL OS API IMPLEMENTATION
//
//----------------------------------------------------------------------------
#include "osdep.h"
#include "PAL_CFG.h"
#include "pal_osapi.h"
#include "amp_db.h"
#include "bt_debug.h"
#include "paldebug.h"
#include "poshApi.h"

#define OS_API_DEBUG
#define OS_ERROR   1
#define OS_NORMAL  2
#define OS_PROTO   3
#define KEY_LENGTH 32

#define PalIsListEmpty(ListHead) (((ListHead)->Flink == (ListHead)))

#define IsNodeConnected(n) (((n)->Blink->Flink == (n)) && ((n)->Flink->Blink == (n)))

#define InitializeListEntry(Entry) ((Entry)->Flink = (Entry)->Blink = 0)
#define InitializeListHead(ListHead) ((ListHead)->Flink = (ListHead)->Blink = (ListHead))

void PalInsertHeadList(ListEntry *head, ListEntry *entry);
A_UINT8 PalIsListCircular(ListEntry* list);
void PalRemoveEntryList(ListEntry* entry);

static void os_gettick(systime_t* _time);

A_UINT8 PAL_Timer_Init(AMP_DEV *Dev)
{
   /*
    *	init timer thread
    */
   Dev->PAL_PoshDebug_level = OS_PROTO;
   PAL_PRINT(("PAL Timer init called, Init_Flag (%d)\n", Dev->PalTimerList.PAL_timerInit));

   if (Dev->PalTimerList.PAL_timerInit != 0){
     OS_assert(0);
     DEBUGP(DBG_PAL, DL_ERROR, ("PAL timer has already inited\n"));
     return(POSH_FAILED);
   }
   
   Dev->PalTimerList.PAL_SysTick = 0; //always starts from 0
   //Loopback our timer list, standard process
   InitializeListHead(&(Dev->PalTimerList.PAL_timerlist));

   Dev->PalTimerList.PAL_timerInit = 1;
   PAL_PRINT(("PAL Timer init success\n"));
   return(POSH_OK);
}

//==========================================================================================
// Set a periodic timer with a call back function
// NOTE! the timer must be freed by the calling function when it is not needed any more
//==========================================================================================
A_UINT32 pal_settimer(AMP_DEV *Dev, A_UINT32 ms, callbackfunc cb, void* context, PAL_TIMER* timer)
{

    PAL_PRINT(("os_settimer called\n"));

    OS_assert(timer != NULL);
    if (timer == NULL) return(POSH_FAILED);

    OS_assert(cb != NULL);  if (cb == NULL) return(POSH_FAILED);
    
    timer->context = context;
    timer->cb = cb;
    timer->duration = ms;
    timer->start_tick = Dev->PalTimerList.PAL_SysTick;
    PAL_PRINT(("os_settimer success(ms:%d), StartTick (%ul)\n", ms, timer->start_tick));
    spin_lock(&Dev->PalTimerList.PAL_timerLock); 
    PalInsertHeadList(&Dev->PalTimerList.PAL_timerlist, &timer->node);
    spin_unlock(&Dev->PalTimerList.PAL_timerLock); 

    return(POSH_OK);

}

void pal_cleartimer(AMP_DEV *Dev, PAL_TIMER* timerid)
{
    PAL_PRINT(("pal_cleartimer called\n"));

    if (timerid->node.Flink == 0)
    {
        PAL_PRINT(("PAL_Timer: Already removed from list\n"));
        return;
    }

    spin_lock(&Dev->PalTimerList.PAL_timerLock); 
    PalRemoveEntryList(&(timerid->node));
    spin_unlock(&Dev->PalTimerList.PAL_timerLock); 

}

/*---------------------------------------------------------------------------
 *            IsListCircular()
 *---------------------------------------------------------------------------
 *
 * Synopsis:  Determine if the list is circular. This is only used for
 *            debugging purposes.
 *
 * Return:    TRUE - the list is circular
 *            FALSE - the list is not circular.
 */
A_UINT8 PalIsListCircular(ListEntry* list)
{
  ListEntry* tmp = list;

  OS_assert(list); if (list == NULL) return(FALSE);
  OS_assert(list->Flink); if (list->Flink == NULL) return(FALSE);

  OS_assert(IsNodeConnected(list));

  if (!IsNodeConnected(list))
    return(FALSE);

  for (tmp = tmp->Flink; tmp != list; tmp = tmp->Flink)
  {
    OS_assert(IsNodeConnected(list));

    if (!IsNodeConnected(tmp))
       return(FALSE);
  }
  return(TRUE);

}

/*---------------------------------------------------------------------------
 *           PalRemoveEntryList()
 *---------------------------------------------------------------------------
 *
 * Synopsis:  Remove the given entry from the list.
 *
 * Return:    void
 *
 */
void PalRemoveEntryList(ListEntry* entry)
{
  OS_assert(PalIsListCircular(entry)); 
  
  if (PalIsListCircular(entry) == FALSE) 
  {
      PAL_PRINT(("PAL-Remove Entry List (%X) failed \n", entry));   
      return;
  }

  entry->Blink->Flink = entry->Flink;
  entry->Flink->Blink = entry->Blink;
  InitializeListEntry(entry);

}


/*---------------------------------------------------------------------------
 *            PalInsertHeadList()
 *---------------------------------------------------------------------------
 *
 * Synopsis:  Insert an entry at the head of the list specified by head.
 *
 * Return:    void
 */
void PalInsertHeadList(ListEntry* head, ListEntry* entry)
{
  OS_assert(PalIsListCircular(head)); 
  if (PalIsListCircular(head) == FALSE)
  {
      PAL_PRINT(("PAL-Insert Head (%X) List Failed \n", head));
      return;
  }

  entry->Flink = head->Flink;
  entry->Blink = head;
  head->Flink->Blink = entry;
  head->Flink = entry;
  OS_assert(PalIsListCircular(head));

}


static void os_gettick(systime_t* _time)
{
    NdisGetCurrentSystemTime((PLARGE_INTEGER)_time);
}

//------------------------------------------------------------
// A very simple timer engine that walks through all the
// registered nodes to see if any of the timer has to be fired.
// This is called by PAL processing thread every 20 mS whenever
// the processing thread is called by the timer
//------------------------------------------------------------
void PAL_timer_process(PAL_TIMER_LIST* PAL_TimerList)
{
    PAL_TIMER*  timer;
    ListEntry*  node;
    systime_t   time_elapsed;
    systime_t   CurrTick;

    //Race condition check to avoid BSOD
    if ((PAL_TimerList->PAL_timerInit == 0) || (PAL_TimerList->PAL_timerlist.Flink == NULL))
    {
        PAL_PRINT(("PAL timer engine accessed prior to initialization \n"));
        return;
    }
    
    CurrTick = PAL_TimerList->PAL_SysTick = (PAL_TimerList->PAL_SysTick+PAL_PROCESS_INTERVAL_MS);

    if (!PalIsListEmpty(&PAL_TimerList->PAL_timerlist)){
        /*
         *   check timer entry and fire timer
         */
        spin_lock(&PAL_TimerList->PAL_timerLock); 
        node = PAL_TimerList->PAL_timerlist.Flink;
        
        //We have someting to process?
        while (node != &PAL_TimerList->PAL_timerlist) {
            //Yes, get current node as timer
            timer = (PAL_TIMER*)node;
            //Move to next node in the list
            node = node->Flink;

            if (CurrTick >= timer->start_tick)
                time_elapsed = CurrTick - timer->start_tick;
            else
                time_elapsed = ((systime_t)(-1) - timer->start_tick + CurrTick); 

            /*
             * Fire the timer
             */
            if (time_elapsed >= timer->duration){
                //os_report(OS_PROTO, ("timer(%x) fired\n", (A_UINT32)timer));
              
                PAL_PRINT(("Timer Fired, Timer ID (%d) \n", timer->timer_type));
                PAL_PRINT(("CurrTick = %d, \n", CurrTick));
//                    PAL_PRINT(("Timer Node, StartTick = %d \n", timer->start_tick));

                OS_assert(timer->cb != NULL);
                if (timer->cb == NULL) {
                    spin_unlock(&PAL_TimerList->PAL_timerLock);
                    return;
                }    

                timer->cb(timer->context);
                PalRemoveEntryList(&(timer->node));
            }
        }

        spin_unlock(&PAL_TimerList->PAL_timerLock);
    }
}
