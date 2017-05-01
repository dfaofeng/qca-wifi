#ifndef _OSIF_H_
#define _OSIF_H_

#ifdef DEVDRVIF_DLL
#define DEVDRVIF_API __declspec(dllexport)
#else
#define DEVDRVIF_API __declspec(dllimport)
#endif

extern DEVDRVIF_API void *cmd_getDevHandle ();
extern DEVDRVIF_API int cmd_init (char *ifname, void (*rx_cb)(void *buf));
extern DEVDRVIF_API int cmd_end ();
extern DEVDRVIF_API void cmd_send (void *buf, int len, unsigned char responseNeeded );
extern DEVDRVIF_API int cmd_send2 (void *buf, int len, unsigned char *returnBuf, unsigned int *returnBufSize );
extern DEVDRVIF_API int cmd_Art2ReadTargetMem (ULONG Address, ULONG Length, PUCHAR ReadBuffer);
extern DEVDRVIF_API int cmd_Art2WriteTargetMem (ULONG Address, ULONG Length, PUCHAR WriteBuffer);
extern DEVDRVIF_API int cmd_Art2ReadTargetRegister (ULONG Address, PULONG ReadBuffer);
extern DEVDRVIF_API int cmd_Art2WriteTargetRegister (ULONG Address, ULONG RegContent);
extern DEVDRVIF_API int cmd_Art2StartFwDownloading (DWORD FwDlFlags);
extern DEVDRVIF_API int cmd_Art2ConcludeBmi ();
extern DEVDRVIF_API int cmd_Art2GetInitStatus ();
extern DEVDRVIF_API DWORD probe_device();
extern DEVDRVIF_API DWORD cmd_Art2ReadPciConfigSpace (ULONG	Offset);
extern DEVDRVIF_API DWORD cmd_Art2WritePciConfigSpace(ULONG Offset, ULONG Data);

void prepare_for_cmd_evt_dump();
void clearup_for_cmd_evt_dump();
void lock_dump();
void unlock_dump();
void dump_cmd(unsigned char *buf, int len);
void dump_evt(unsigned char *buf, int len);
void dump_hex(unsigned char *buf, int len);


#endif /* _OSIF_H_ */
