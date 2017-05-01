/*
 * Copyright (c) 2012, Qualcomm Atheros Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <linux/module.h>
#include <adf_os_perf.h>

MODULE_AUTHOR("QUalcomm Atheros Inc.");
MODULE_DESCRIPTION("Qualcomm Atheros Device Framework Module");
MODULE_LICENSE("Dual BSD/GPL");

#ifndef EXPORT_SYMTAB
#define EXPORT_SYMTAB
#endif

#define TIMER_COUNT 256

spinlock_t timer_list_lock_bh;
int timer_index=0;
struct timer_list   *trace_timer[TIMER_COUNT] ;
EXPORT_SYMBOL(trace_timer);
EXPORT_SYMBOL(timer_index);
EXPORT_SYMBOL(timer_list_lock_bh);

static int __init 
adf_os_mod_init(void)
{
    int i ;
    spin_lock_init(&timer_list_lock_bh); 
    for ( i = 0 ; i < TIMER_COUNT ; i++ ) {
      trace_timer[i] = NULL ;
    }
    printk("****Address of trace_timer :%p \n",&trace_timer);
    adf_os_perfmod_init();
    return 0;
}

static void __exit 
adf_os_mod_exit(void)
{
    adf_os_perfmod_exit();
}

module_init(adf_os_mod_init);
module_exit(adf_os_mod_exit);

