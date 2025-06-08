#include <string.h>
#include "esp_log.h"

#if CONFIG_WIFI_NEED_THIS_FILE
static const char *TAG = "wifi_connect";
static esp_netif_t *s_sta_netif = NULL;
#endif
