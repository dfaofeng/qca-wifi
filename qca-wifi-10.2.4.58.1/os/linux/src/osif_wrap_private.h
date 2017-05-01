#ifndef _OSIF_WRAP_PRIVATE_H_
#define _OSIF_WRAP_PRIVATE_H_

#define	WRAP_DEV_HASHSIZE	32	/*dev hash table size*/
#define WRAP_PROC_FILE				"wrap"
#if ATH_SUPPORT_WRAP_BRIDGE
#define WRAP_PROC_MAX_FILE_LENGTH     15
#define WRAP_PROC_PERM              0644
#endif

/*Proc cmds*/
#define WRAP_PROC_CMD_ISOLATION		1

#define OSIF_TO_NETDEV(_osif) 		(((osif_dev *)(_osif))->netdev)
#define OSIF_TO_DEVNAME(_osif) 		(((osif_dev *)(_osif))->netdev->name)

//device table simple hash function
#define	WRAP_DEV_HASH(addr)   \
    (((const u_int8_t *)(addr))[IEEE80211_ADDR_LEN - 1] % WRAP_DEV_HASHSIZE)

//#define DEBUG 0					//only for extra debugging
#if DEBUG
#define OSIF_WRAP_MSG_MORE(string, args...) 	printk("%s:%d " string, __func__,__LINE__, ##args)
#else
#define OSIF_WRAP_MSG_MORE(string, args...) 
#endif

#define OSIF_WRAP_MSG(string, args...) 		printk(KERN_INFO "%s:%d " string, __func__,__LINE__, ##args)
#define OSIF_WRAP_MSG_ERR(string, args...) 	printk(KERN_ERR "%s:%d " string, __func__,__LINE__, ##args)
#define OSIF_WRAP_MSG_SHORT(string, args...) 	printk(string, ##args)

#define OSIF_WRAP_PROC_CMD_OFFSET 0
#define OSIF_WRAP_PROC_ARG_OFFSET 2

typedef rwlock_t wrap_devt_lock_t;

//wrap device table
typedef struct wrap_devt
{
	struct wrap_com 			*wdt_wc;	/*back ptr to wrap com*/
	wrap_devt_lock_t        	wdt_lock; 	/*lock for the dev table*/
	u_int8_t					wdt_dev_cnt;	/*device count*/
	TAILQ_HEAD(,_osif_dev)		wdt_dev;	/*head for device list*/
	ATH_LIST_HEAD(,_osif_dev)	wdt_hash[WRAP_DEV_HASHSIZE]; /*head for device hash*/
} wrap_devt_t;

//wrap common struct
typedef struct wrap_com 
{
	struct wrap_devt		wc_devt;	/*wrap device table*/	
	struct nf_hook_ops 		*wc_nfops;	/*wrap nf hook ops*/
	struct proc_dir_entry 	*wc_proc_entry;
#if ATH_SUPPORT_WRAP_BRIDGE
    const char              *wc_proc_name;
#endif
	u_int8_t 				wc_isolation;
	int wc_use_cnt;						/*wrap comm use cnt*/
	char wc_addr[IEEE80211_ADDR_LEN];	
} wrap_com_t;

#if !(ATH_SUPPORT_WRAP_BRIDGE)
static unsigned int osif_wrap_handle_pre_route(unsigned int hooknum,
                        struct sk_buff *skb,
                                const struct net_device *in,
                                const struct net_device *out,
                                int (*okfn)(struct sk_buff *));

static unsigned int osif_wrap_handle_forward(unsigned int hooknum,
                        struct sk_buff *skb,
                                const struct net_device *in,
                                const struct net_device *out,
                                int (*okfn)(struct sk_buff *));

static unsigned int osif_wrap_handle_post_route(unsigned int hooknum,
                        struct sk_buff *skb,
                                const struct net_device *in,
                                const struct net_device *out,
                                int (*okfn)(struct sk_buff *));

static unsigned int osif_wrap_handle_local_in(unsigned int hooknum,
                        struct sk_buff *skb,
                                const struct net_device *in,
                                const struct net_device *out,
                                int (*okfn)(struct sk_buff *));
#endif
#endif
