#include <linux/skbuff.h>
#include <linux/netfilter.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/netfilter_bridge.h>
#include <linux/if_bridge.h>
#include <linux/proc_fs.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0)
#include <fs/proc/internal.h>
#endif
#include <sys/queue.h>
#include "osif_private.h"
#include "osif_wrap_private.h"
#include "osif_wrap.h"
#include "if_athvar.h"


static void osif_wrap_devt_init(struct wrap_com *wc, struct wrap_devt *wdt);
int osif_wrap_proc_write(struct file *file, const char *buffer, unsigned long count, void *data)
{
	char buf[3];
	struct wrap_com *wc=(struct wrap_com*)data;
	u_int32_t arg,cmd;	

	if (count > (sizeof(buf)+2)) {
		return -EINVAL;
	}

	if (copy_from_user(buf,buffer,count)) {
		return -EFAULT;
	}		
	
	cmd = (u_int32_t)simple_strtoul(&buf[OSIF_WRAP_PROC_CMD_OFFSET],NULL,10);
	arg = (u_int32_t)simple_strtoul(&buf[OSIF_WRAP_PROC_ARG_OFFSET],NULL,10);

	switch (cmd) {
		case WRAP_PROC_CMD_ISOLATION:
			if(arg == 1)
				wc->wc_isolation = 1;		
			else
				wc->wc_isolation = 0;		
			OSIF_WRAP_MSG("WRAP isolation %d\n",wc->wc_isolation);	
		break;
		default:
			OSIF_WRAP_MSG("Invalid cmd\n");	
			return -EINVAL;
		break;
	}

	return(count);	
}

#if ATH_SUPPORT_WRAP_BRIDGE


int osif_wrap_proc_read(char *buf, char **start, off_t offset, int count, int *eof, void *data)
{
	struct wrap_com *wc=(struct wrap_com*)data;
	struct wrap_devt *wdt = &wc->wc_devt;
	osif_dev *osd;
	int len=0;
	struct net_device *netdev;
#if notyet
    int type=-1;
#endif

	if(TAILQ_EMPTY(&wdt->wdt_dev))
		return 0;

	len += sprintf(buf+len,"Isolation is %s\n",(wc->wc_isolation==1)?"enabled":"disabled");
	len += sprintf(buf+len,"%-4s [ type][%-17s] [d:o:s]\n","dev","oma");
	TAILQ_FOREACH(osd, &wdt->wdt_dev, osif_dev_list) {
		netdev = OSIF_TO_NETDEV(osd);
#if notyet
		if(netdev->br_port)
			type  = br_get_port_type(netdev->br_port);
			len += sprintf(buf+len,"%s [%d][%s] [%lu:%lu:%lu]\n",	
			OSIF_TO_DEVNAME(osd),type,
			ether_sprintf(osd->osif_dev_oma),
			osd->osif_dev_cnt_drp,osd->osif_dev_cnt_ovrd,
			osd->osif_dev_cnt_stl);
#endif
	}

 	if(len <= count + offset )
        *eof = 1;
    *start = buf + offset; 
    len -= offset;
   
    if(len > count )
        len = count; 
    if(len < 0 )
        len = 0;
 
    return len;
}
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0)
static const struct file_operations fops = {
         .read = osif_wrap_proc_read,
         .write = osif_wrap_proc_write,
         .llseek = default_llseek,
 };
#endif


static unsigned int proc_idx=0;
/**
 * @brief WRAP proc fs init
 *
 * @param wc Ptr to the wrap common. 
 *
 * @return void
 */
static void osif_wrap_proc_init(struct wrap_com *wc)
{
	struct proc_dir_entry *proc_entry = wc->wc_proc_entry;
    char tmp[WRAP_PROC_MAX_FILE_LENGTH], *tmp1;

    tmp1 = OS_MALLOC(NULL,sizeof(char)*WRAP_PROC_MAX_FILE_LENGTH,GFP_KERNEL);
    if (!tmp1) {
        OSIF_WRAP_MSG_ERR("Failed to alloc mem for wrap proc entry \n");
        return;
    }
    snprintf(tmp, sizeof(tmp),
                       WRAP_PROC_FILE "%d\0", proc_idx++);
    OS_MEMCPY(tmp1,tmp,strlen(tmp)); 
    if (tmp1)
        wc->wc_proc_name = tmp1;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0)
    proc_entry = proc_create_data(wc->wc_proc_name, WRAP_PROC_PERM, NULL,&fops,(void *)(wc));
#else
    proc_entry = create_proc_entry(wc->wc_proc_name, WRAP_PROC_PERM, NULL);
    proc_entry->nlink = 1;
    proc_entry->data = (void *)(wc);
    proc_entry->read_proc = osif_wrap_proc_read;
    proc_entry->write_proc = osif_wrap_proc_write;
#endif
	return;
}

/**
 * @brief WRAP proc fs remove
 *
 * @param wc Ptr to the wrap common. 
 *
 * @return void
 */
static void osif_wrap_proc_remove(struct wrap_com *wc)
{
    if(wc->wc_proc_name) {
        remove_proc_entry(wc->wc_proc_name,NULL);
        OS_FREE(wc->wc_proc_name);
    }
	return;
}

/**
 * @brief Add wrap dev object to the device table, also 
 * registers bridge hooks if this the first object.
 *
 * @param osdev Pointer to osif_dev to add.
 *
 * @return 0 on success 
 * @return -ve on failure 
 */

int osif_wrap_dev_add(osif_dev *osdev)
{
	int hash;
	wlan_if_t vap = osdev->os_if;
    struct wrap_devt *wdt = &vap->iv_ic->ic_wrap_com->wc_devt;
    struct wrap_com *wrap_com = vap->iv_ic->ic_wrap_com;
    rwlock_state_t lock_state;
  
	struct net_device *netdev = OSIF_TO_NETDEV(osdev); 
            
	OSIF_WRAP_MSG("Adding %s to the list mat\n",OSIF_TO_DEVNAME(osdev));	

	if(vap->iv_mat == 1)
		IEEE80211_ADDR_COPY(osdev->osif_dev_oma,vap->iv_mat_addr);
	else
		IEEE80211_ADDR_COPY(osdev->osif_dev_oma,netdev->dev_addr);

    hash = WRAP_DEV_HASH(osdev->osif_dev_oma);
	OS_RWLOCK_WRITE_LOCK(&wdt->wdt_lock,lock_state);
	LIST_INSERT_HEAD(&wdt->wdt_hash[hash], osdev, osif_dev_hash);
	TAILQ_INSERT_TAIL(&wdt->wdt_dev, osdev, osif_dev_list);
	osdev->wrap_handle = wrap_com;
	if(wrap_com->wc_isolation)
		vap->iv_isolation = 1;
	else 
		vap->iv_isolation = 0; 
	wdt->wdt_dev_cnt++;
	OS_RWLOCK_WRITE_UNLOCK(&wdt->wdt_lock,lock_state);
	return 0;
}

/**
 * @brief Delete wrap dev object from the device table, also 
 * unregisters bridge hooks if this the last object.
 *
 * @param osdev Ptr to the osif_dev to delete
 *
 * @return void
 */

void osif_wrap_dev_remove(osif_dev *osdev)
{
	int hash;
	osif_dev *osd;
    wlan_if_t vap = osdev->os_if;
    struct wrap_devt *wdt = &vap->iv_ic->ic_wrap_com->wc_devt;
	rwlock_state_t lock_state;

	hash = WRAP_DEV_HASH(osdev->osif_dev_oma);
	OS_RWLOCK_WRITE_LOCK(&wdt->wdt_lock,lock_state);
 	LIST_FOREACH(osd, &wdt->wdt_hash[hash], osif_dev_hash) {
		if (IEEE80211_ADDR_EQ(osd->osif_dev_oma,osdev->osif_dev_oma)){
		    LIST_REMOVE(osd,osif_dev_hash);
		    TAILQ_REMOVE(&wdt->wdt_dev, osd, osif_dev_list);
		    OSIF_WRAP_MSG("Removing %s from the list\n",OSIF_TO_DEVNAME(osdev));	
		    wdt->wdt_dev_cnt--;
		    OS_RWLOCK_WRITE_UNLOCK(&wdt->wdt_lock,lock_state);
		    return;
		}
    }
	OS_RWLOCK_WRITE_UNLOCK(&wdt->wdt_lock,lock_state);
	return;
}

/**
 * @brief Find wrap dev object based on MAC address. 
 *
 * @param wdt Ptr to the wrap device table.
 * @param mac MAC address to look up.
 *
 * @return osif_dev on success 
 * @return NULL on failure 
 */
osif_dev *osif_wrap_wdev_find(struct wrap_devt *wdt,unsigned char *mac)
{
	osif_dev *osdev;
	int hash;
	rwlock_state_t lock_state;

	hash = WRAP_DEV_HASH(mac);
	OS_RWLOCK_READ_LOCK(&wdt->wdt_lock,lock_state);
	LIST_FOREACH(osdev, &wdt->wdt_hash[hash], osif_dev_hash) {
        	if (IEEE80211_ADDR_EQ(osdev->osif_dev_oma, mac)){ 	
			OS_RWLOCK_READ_UNLOCK(&wdt->wdt_lock,lock_state);
        		return osdev;
		}
	}	
	OS_RWLOCK_READ_UNLOCK(&wdt->wdt_lock,lock_state);
	return NULL;
}

/**
 * @brief wrap device table detach
 *
 * @param wrap comm 
 *
 * @return 
 */
static void osif_wrap_devt_detach(struct wrap_com *wc)
{
    struct wrap_devt *wdt = &wc->wc_devt;
	osif_wrap_proc_remove(wc);
 	OS_RWLOCK_DESTROY(&wdt->wdt_lock);
	wdt->wdt_wc=NULL;	
	OSIF_WRAP_MSG("osif wrap dev table detached\n");	
	return;
}
/**
 * @brief wrap attach
 *
 * @param ic
 *
 * @return 0 on success 
 * @return -ve on failure 
 */
int osif_wrap_attach(wlan_dev_t ic)
{
	int ret=0;
    struct wrap_com *wrap_com;
	if(wrap_com) {
		wrap_com->wc_use_cnt++;
		return 0;
	}
	
	wrap_com = OS_MALLOC(NULL,sizeof(struct wrap_com),GFP_KERNEL);
	if (!wrap_com) {
		OSIF_WRAP_MSG_ERR("Failed to alloc mem for wrap common\n");	
     		return -EINVAL;
     	} else{
		OSIF_WRAP_MSG("osif wrap attached\n");	
	}

	OS_MEMZERO(wrap_com,sizeof(struct wrap_com));
	wrap_com->wc_use_cnt++;
	osif_wrap_devt_init(wrap_com,&wrap_com->wc_devt);
    ic->ic_wrap_com = wrap_com;

	return ret;
}

/**
 * @brief wrap detach 
 *
 * @param ic
 *
 * @return 0 on success 
 * @return -ve on failure 
 */
int osif_wrap_detach(wlan_dev_t ic)
{
	int ret=0;
    struct wrap_com *wrap_com = ic->ic_wrap_com;

	ASSERT(wrap_com != NULL);

	wrap_com->wc_use_cnt--;		

	if(wrap_com->wc_use_cnt==0){		
		osif_wrap_devt_detach(wrap_com);
		OS_FREE(wrap_com);
		wrap_com = NULL;
		OSIF_WRAP_MSG("osif wrap detached\n");	
	}

	return ret;
}
#else
struct wrap_com *wrap_com=NULL;

#define BR_PORT_TYPE(_brport)  (br_get_port_type(_brport)&(PTYPE_MASK))

static struct nf_hook_ops wrap_brhooks[] __read_mostly = {
	{
		.hook     = osif_wrap_handle_pre_route,
		.owner    = THIS_MODULE,
		.pf       = PF_BRIDGE,
		.hooknum  = NF_BR_PRE_ROUTING,
		.priority = NF_BR_PRI_NAT_DST_BRIDGED
	},
	{
		.hook     = osif_wrap_handle_forward,
		.owner    = THIS_MODULE,
		.pf       = PF_BRIDGE,
		.hooknum  = NF_BR_FORWARD,
		.priority = NF_BR_PRI_FILTER_BRIDGED
	},
	{
		.hook     = osif_wrap_handle_post_route,
		.owner    = THIS_MODULE,
		.pf       = PF_BRIDGE,
		.hooknum  = NF_BR_POST_ROUTING,
		.priority = NF_BR_PRI_NAT_SRC
	},
    { 
        .hook     = osif_wrap_handle_local_in,
        .owner    = THIS_MODULE,
        .pf       = PF_BRIDGE,
        .hooknum  = NF_BR_LOCAL_IN,
        .priority = NF_BR_PRI_FILTER_BRIDGED
    },
};

/**
 * @brief Calls hardstart to transmit buf.
 *
 * @param skb 
 *
 * @return 0 on success 
 * @return -ve on failure 
 */
static int osif_wrap_dev_xmit(struct sk_buff *skb)
{
	if ((skb->len) > (skb->dev->mtu))
                kfree_skb(skb);
	else {
		skb_push(skb, ETH_HLEN);
		osif_vap_hardstart(skb,skb->dev);
	}			
	return 0;
}

/**
 * @brief Find wrap dev object based on MAC address. 
 *
 * @param wdt Ptr to the wrap device table.
 * @param mac MAC address to look up.
 *
 * @return osif_dev on success 
 * @return NULL on failure 
 */
osif_dev *osif_wrap_wdev_find(struct wrap_devt *wdt,unsigned char *mac)
{
	osif_dev *osdev;
	int hash;
	rwlock_state_t lock_state;

	hash = WRAP_DEV_HASH(mac);
	OS_RWLOCK_READ_LOCK(wdt->wdt_lock,lock_state);
	LIST_FOREACH(osdev, &wdt->wdt_hash[hash], osif_dev_hash) {
        	if (IEEE80211_ADDR_EQ(osdev->osif_dev_oma, mac)){ 	
			OS_RWLOCK_READ_UNLOCK(wdt->wdt_lock,lock_state);
        		return osdev;
		}
	}	
	OS_RWLOCK_READ_UNLOCK(wdt->wdt_lock,lock_state);
	return NULL;
}

/**
 * @brief Hook to check if local delivery is needed
 *
 * @param skb 
 *
 * @return 0 to bridge the pkt 
 * @return 1 to route the pkt 
 */
static int osif_wrap_brroute_hook(struct sk_buff *skb)
{
	if(WRAP_MARK_IS_ROUTE(skb->mark)) {
		OSIF_WRAP_MSG_MORE("Allowing local delivery [%p]\n",skb);	
		return 1; /* route it */
	}

	return 0; /* bridge it */
}

/**
 * @brief Add wrap dev object to the device table, also 
 * registers bridge hooks if this the first object.
 *
 * @param osdev Pointer to osif_dev to add.
 *
 * @return 0 on success 
 * @return -ve on failure 
 */
int osif_wrap_dev_add(osif_dev *osdev)
{
	int hash,ret;
	struct wrap_devt *wdt = &wrap_com->wc_devt;
	rwlock_state_t lock_state;
	wlan_if_t vap = osdev->os_if;
	struct net_device *netdev = OSIF_TO_NETDEV(osdev); 

	/*set psta mac address to allow ap access*/
    if(vap->iv_mpsta == 1) {
        IEEE80211_ADDR_COPY(wrap_com->wc_addr,vap->iv_mat_addr);
    }
            
	if(wdt->wdt_dev_cnt == 0) {
		ret=nf_register_hooks(wrap_brhooks,sizeof(wrap_brhooks)/sizeof(wrap_brhooks[0]));
		if(ret<0) {
			OSIF_WRAP_MSG_ERR("Failed to register br hooks\n");	
			return ret;
		}
		//register hook to intercept pkt to support local delivery	
		rcu_assign_pointer(br_should_route_hook,osif_wrap_brroute_hook);
	}

	OSIF_WRAP_MSG("Adding %s to the list mat\n",OSIF_TO_DEVNAME(osdev));	

	if(vap->iv_mat == 1)
		IEEE80211_ADDR_COPY(osdev->osif_dev_oma,vap->iv_mat_addr);
	else
		IEEE80211_ADDR_COPY(osdev->osif_dev_oma,netdev->dev_addr);

    hash = WRAP_DEV_HASH(osdev->osif_dev_oma);
	OS_RWLOCK_WRITE_LOCK(wdt->wdt_lock,lock_state);
	LIST_INSERT_HEAD(&wdt->wdt_hash[hash], osdev, osif_dev_hash);
	TAILQ_INSERT_TAIL(&wdt->wdt_dev, osdev, osif_dev_list);
	osdev->wrap_handle = wrap_com;
	if(wrap_com->wc_isolation)
		vap->iv_isolation = 1;
	else 
		vap->iv_isolation = 0; 
	wdt->wdt_dev_cnt++;
	OS_RWLOCK_WRITE_UNLOCK(wdt->wdt_lock,lock_state);
	return 0;
}

/**
 * @brief Delete wrap dev object from the device table, also 
 * unregisters bridge hooks if this the last object.
 *
 * @param osdev Ptr to the osif_dev to delete
 *
 * @return void
 */
void osif_wrap_dev_remove(osif_dev *osdev)
{
	int hash;
	osif_dev *osd;
	struct wrap_devt *wdt = &wrap_com->wc_devt;
	rwlock_state_t lock_state;

	hash = WRAP_DEV_HASH(osdev->osif_dev_oma);
	OS_RWLOCK_WRITE_LOCK(wdt->wdt_lock,lock_state);
 	LIST_FOREACH(osd, &wdt->wdt_hash[hash], osif_dev_hash) {
		if (IEEE80211_ADDR_EQ(osd->osif_dev_oma,osdev->osif_dev_oma)){
		    LIST_REMOVE(osd,osif_dev_hash);
		    TAILQ_REMOVE(&wdt->wdt_dev, osd, osif_dev_list);
		    OSIF_WRAP_MSG("Removing %s from the list\n",OSIF_TO_DEVNAME(osdev));	
		    wdt->wdt_dev_cnt--;
		    OS_RWLOCK_WRITE_UNLOCK(wdt->wdt_lock,lock_state);
		    if(wdt->wdt_dev_cnt == 0) {
			nf_unregister_hooks(wrap_brhooks,sizeof(wrap_brhooks)/sizeof(wrap_brhooks[0]));
			OSIF_WRAP_MSG("Removing hooks\n");	
			//reset the br route hook
			rcu_assign_pointer(br_should_route_hook, NULL);
		    }
		    return;
		}
    }
	OS_RWLOCK_WRITE_UNLOCK(wdt->wdt_lock,lock_state);
	return;
}

/**
 * @brief bridge PREROUTE wrap hook
 *
 * @param hooknum Hook number
 * @param skb 
 * @param in IN port device.
 * @param out OUT port device.
 * @param okfn OK call back function.
 *
 * @return NF_ACCEPT To accept the frame.
 * @return NF_DROP To drop the frame.
 */
static unsigned int osif_wrap_handle_pre_route(unsigned int hooknum,
                        struct sk_buff *skb,
                                const struct net_device *in,
                                const struct net_device *out,
                                int (*okfn)(struct sk_buff *))
{
	u_int8_t ismcast;
	osif_dev *osd_src;
	int type  = BR_PORT_TYPE(in->br_port);

	ismcast = IEEE80211_IS_MULTICAST(eth_hdr(skb)->h_dest);
	
	OSIF_WRAP_MSG_MORE("%s:%d [%p]\n",in->name,type,skb);	

	switch(type)
	{
		case WRAP_PTYPE_ETH:
		case WRAP_PTYPE_VAP:
			if(wrap_com->wc_isolation){
				OSIF_WRAP_MSG_MORE("%s:%d [%p]\n",in->name,type,skb);	

            	if(IEEE80211_ADDR_EQ(eth_hdr(skb)->h_dest,wrap_com->wc_addr))
					return NF_ACCEPT;

				osd_src=osif_wrap_wdev_find(&wrap_com->wc_devt,eth_hdr(skb)->h_source);
				if(osd_src){
					struct sk_buff *skb2;
					if((skb2=skb_clone(skb,GFP_ATOMIC))==NULL){
						OSIF_WRAP_MSG_ERR("Failed to alloc memory\n");
						return NF_DROP;
					}
					skb2->dev = OSIF_TO_NETDEV(osd_src); 
					/*let this pkt to go through the bridge for learning 
					  will be dropped in the forward hook so mark it*/
					OSIF_WRAP_MSG_MORE("%s:%d sending to %s [%p]\n",in->name,type,skb2->dev->name,skb2);	
					skb->mark |= WRAP_MARK_DROP;
					osif_wrap_dev_xmit(skb2);		
					return NF_ACCEPT;
				}else
					return NF_DROP;
			}
		break;
		case WRAP_PTYPE_PETH:
		case WRAP_PTYPE_PVAP:
			/*Already filtered out in driver, but in case?*/
			if(WRAP_MARK_IS_REFLECT(skb->mark))
				return NF_DROP;	
		break;
		case WRAP_PTYPE_MPVAP:
			if(wrap_com->wc_isolation == 0){
				if(WRAP_MARK_IS_REFLECT(skb->mark))
					return NF_DROP;	
			}	
		break;
		default:
		break;
	}
	
	return NF_ACCEPT;
}

/**
 * @brief bridge FORWARD wrap hook
 *
 * @param hooknum Hook number
 * @param skb 
 * @param in IN port device.
 * @param out OUT port device.
 * @param okfn OK call back function.
 *
 * @return NF_ACCEPT To accept the frame.
 * @return NF_DROP To drop the frame.
 */
static unsigned int osif_wrap_handle_forward(unsigned int hooknum,
                        struct sk_buff *skb,
                                const struct net_device *in,
                                const struct net_device *out,
                                int (*okfn)(struct sk_buff *))
{
	int intype = BR_PORT_TYPE(in->br_port);
	int outtype = BR_PORT_TYPE(out->br_port);
	osif_dev *osd_src;
	u_int8_t ismcast;

	ismcast = IEEE80211_IS_MULTICAST(eth_hdr(skb)->h_dest);

	if(wrap_com->wc_isolation){
		if(intype == WRAP_PTYPE_ETH || intype == WRAP_PTYPE_VAP) {
			if(WRAP_MARK_IS_DROP(skb->mark)){
				OSIF_WRAP_MSG_MORE("%s:%d dropping [%p]\n",in->name,intype,skb);	
					return NF_DROP;
			}
			return NF_ACCEPT;
		}

		if(ismcast && (intype==WRAP_PTYPE_MPVAP) 
		/* This is to drop multicast pkt reflection for ethernet client*/		
			&& (outtype == WRAP_PTYPE_ETH)){
				osd_src=osif_wrap_wdev_find(&wrap_com->wc_devt,eth_hdr(skb)->h_source);
				if(osd_src){
					struct net_device *netdev;
					int type;
					netdev = OSIF_TO_NETDEV(osd_src);
					type  = BR_PORT_TYPE(netdev->br_port);
					if(type == WRAP_PTYPE_PETH)
						return NF_DROP;	
				}
		}

		//this says in port is mpvap|pvap|peth
		if(outtype == WRAP_PTYPE_PVAP || outtype == WRAP_PTYPE_PETH){
				return NF_DROP;	
		}
	}
	return NF_ACCEPT;
}

/**
 *  @brief bridge INPUT wrap hook
 *
 * @param hooknum Hook number
 * @param skb 
 * @param in IN port device.
 * @param out OUT port device.
 * @param okfn OK call back function.
 *
 * @return NF_ACCEPT To accept the frame.
 * @return NF_DROP To drop the frame.
 */
static unsigned int osif_wrap_handle_local_in(unsigned int hooknum,
                                struct sk_buff *skb,
                                        const struct net_device *in,
                                        const struct net_device *out,
                                        int (*okfn)(struct sk_buff *))
{
	int type = BR_PORT_TYPE(in->br_port);

	switch(type){
		case WRAP_PTYPE_MPVAP:
		    if(WRAP_MARK_IS_REFLECT(skb->mark))
				return NF_DROP;	
        break;
        default:
        break;
    }
    return NF_ACCEPT;
}


/**
 * @brief bridge POSTROUTE wrap hook
 *
 * @param hooknum Hook number
 * @param skb 
 * @param in IN port device.
 * @param out OUT port device.
 * @param okfn OK call back function.
 *
 * @return NF_ACCEPT To accept the frame.
 * @return NF_DROP To drop the frame.
 */
static unsigned int osif_wrap_handle_post_route(unsigned int hooknum,
                        struct sk_buff *skb,
                                const struct net_device *in,
                                const struct net_device *out,
                                int (*okfn)(struct sk_buff *))
{
	osif_dev *osdev,*osd_src;
	u_int8_t ismcast;
	int type  = BR_PORT_TYPE(out->br_port);


	ismcast = IEEE80211_IS_MULTICAST(eth_hdr(skb)->h_dest);

	switch(type){
		case WRAP_PTYPE_PVAP:
		case WRAP_PTYPE_MPVAP:
		case WRAP_PTYPE_PETH:
			osdev = ath_netdev_priv(out);
			OSIF_WRAP_MSG_MORE("%s:%d [%p]\n",out->name,type,skb);	

			if((IEEE80211_ADDR_EQ(eth_hdr(skb)->h_source,osdev->osif_dev_oma))
				|| (IEEE80211_ADDR_EQ(eth_hdr(skb)->h_source,out->dev_addr))) {
					/*bridge decision ok, let it go*/
					OSIF_WRAP_MSG_MORE("%s:%d [%p]\n",out->name,type,skb);	
					return NF_ACCEPT;
			}
			
			if(ismcast || WRAP_MARK_IS_FLOOD(skb->mark)){
				OSIF_WRAP_MSG_MORE("%s:%d dropping [%p]\n",out->name,type,skb);	
				return NF_DROP;
			}else{
				/*override bridge decision*/
				osd_src=osif_wrap_wdev_find(&wrap_com->wc_devt,eth_hdr(skb)->h_source);
				if(osd_src){
					OSIF_WRAP_MSG_MORE("%s:%d sending to %s [%p]\n",in->name,type,skb->dev->name,skb);	
					skb->dev = OSIF_TO_NETDEV(osd_src); 
					osif_wrap_dev_xmit(skb);		
					osdev->osif_dev_cnt_stl++;
					osd_src->osif_dev_cnt_ovrd++;
					return NF_STOLEN;
				}else {
					OSIF_WRAP_MSG_MORE("%s:%d dropping [%p]\n",out->name,type,skb);	
					osdev->osif_dev_cnt_drp++;
					return NF_DROP;
                }
			}	
		break;
		default:
		break;
	}	
	
	return NF_ACCEPT;
}


int osif_wrap_proc_read(char *buf, char **start, off_t offset, int count, int *eof, void *data)
{
	struct wrap_com *wc=(struct wrap_com*)data;
	struct wrap_devt *wdt = &wc->wc_devt;
	osif_dev *osd;
	int len=0;
	struct net_device *netdev;
	int type=-1;

	if(TAILQ_EMPTY(&wdt->wdt_dev))
		return 0;

	len += sprintf(buf+len,"Isolation is %s\n",(wc->wc_isolation==1)?"enabled":"disabled");
	len += sprintf(buf+len,"%-4s [ type][%-17s] [d:o:s]\n","dev","oma");
	TAILQ_FOREACH(osd, &wdt->wdt_dev, osif_dev_list) {
		netdev = OSIF_TO_NETDEV(osd);
		if(netdev->br_port)
			type  = br_get_port_type(netdev->br_port);
			len += sprintf(buf+len,"%s [%d][%s] [%lu:%lu:%lu]\n",	
			OSIF_TO_DEVNAME(osd),type,
			ether_sprintf(osd->osif_dev_oma),
			osd->osif_dev_cnt_drp,osd->osif_dev_cnt_ovrd,
			osd->osif_dev_cnt_stl);
	}

 	if(len <= count + offset )
        *eof = 1;
    *start = buf + offset; 
    len -= offset;
   
    if(len > count )
        len = count; 
    if(len < 0 )
        len = 0;
 
    return len;
}

/**
 * @brief WRAP proc fs init
 *
 * @param wc Ptr to the wrap common. 
 *
 * @return void
 */
static void osif_wrap_proc_init(struct wrap_com *wc)
{
	struct proc_dir_entry *proc_entry = wc->wc_proc_entry;

	proc_entry = create_proc_entry(WRAP_PROC_FILE,0644,NULL);
 	proc_entry->nlink = 1;
    proc_entry->data = (void *)(wc);
    proc_entry->read_proc = osif_wrap_proc_read;
    proc_entry->write_proc = osif_wrap_proc_write;
	
	return;
}

/**
 * @brief WRAP proc fs remove
 *
 * @param wc Ptr to the wrap common. 
 *
 * @return void
 */
static void osif_wrap_proc_remove(void)
{
	remove_proc_entry(WRAP_PROC_FILE,NULL);
	return;
}

/**
 * @brief wrap device table detach
 *
 * @param wrap comm 
 *
 * @return 
 */
static void osif_wrap_devt_detach(struct wrap_com *wc)
{
	struct wrap_devt *wdt = &wrap_com->wc_devt;

	osif_wrap_proc_remove();
 	OS_RWLOCK_DESTROY(&wdt->wdt_lock);
	wdt->wdt_wc=NULL;	
	OSIF_WRAP_MSG("osif wrap dev table detached\n");	
	return;
}

/**
 * @brief wrap attach
 *
 * @param void
 *
 * @return 0 on success 
 * @return -ve on failure 
 */
int osif_wrap_attach(void)
{
	int ret=0;

	if(wrap_com) {
		wrap_com->wc_use_cnt++;
		return 0;
	}
	
	wrap_com = OS_MALLOC(NULL,sizeof(struct wrap_com),GFP_KERNEL);
	if (!wrap_com) {
		OSIF_WRAP_MSG_ERR("Failed to alloc mem for wrap common\n");	
     		return -EINVAL;
     	} else{
		OSIF_WRAP_MSG("osif wrap attached\n");	
	}

	OS_MEMZERO(wrap_com,sizeof(struct wrap_com));
	wrap_com->wc_use_cnt++;
	osif_wrap_devt_init(wrap_com,&wrap_com->wc_devt);

	return ret;
}

/**
 * @brief wrap detach 
 *
 * @param void
 *
 * @return 0 on success 
 * @return -ve on failure 
 */
int osif_wrap_detach(void)
{
	int ret=0;

	ASSERT(wrap_com != NULL);

	wrap_com->wc_use_cnt--;		

	if(wrap_com->wc_use_cnt==0){		
		osif_wrap_devt_detach(wrap_com);
		OS_FREE(wrap_com);
		wrap_com = NULL;
		OSIF_WRAP_MSG("osif wrap detached\n");	
	}

	return ret;
}
#endif
/**
 * @brief WRAP device table attach
 *
 * @param wc Ptr to the wrap common. 
 * @param wdt Ptr to wrap device table. 
 *
 * @return void
 */
static void osif_wrap_devt_init(struct wrap_com *wc, struct wrap_devt *wdt)
{
	int i;

 	OS_RWLOCK_INIT(&wdt->wdt_lock);
	TAILQ_INIT(&wdt->wdt_dev);
	for(i=0;i<WRAP_DEV_HASHSIZE;i++)
		 LIST_INIT(&wdt->wdt_hash[i]);
	wdt->wdt_wc=wc;	
	osif_wrap_proc_init(wc);
	OSIF_WRAP_MSG("osif wrap dev table init done\n");	
	return;
}
