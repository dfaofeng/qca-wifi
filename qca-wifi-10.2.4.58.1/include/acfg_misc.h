//#define acfg_min(x, y)   ((x) < (y) ? (x) : (y))
//#define acfg_max(x, y)   ((x) > (y) ? (x) : (y))
#define ACFG_STR_MATCH(str1, str2)  (strcmp(((char *)str1), ((char *)str2)) == 0)
#define ACFG_N_STR_MATCH(str1, str2)  (strncmp(((char *)str1), ((char *)str2), strlen((char*)str2)) == 0)
#define ACFG_MAC_STR_LEN         17
#define ACFG_ENABLE_PARAM "enable"
#define ACFG_DISABLE_PARAM "disable"
#define ACFG_HTOLE16(X)  (((((uint16_t)(X)) << 8) | ((uint16_t)(X) >> 8)) & 0xffff)
