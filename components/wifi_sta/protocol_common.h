#pragma once

#include "sdkconfig.h"
#include "esp_err.h"
#include "esp_netif.h"

#define CONFIG_CONNECT_WIFI 1

#ifdef __cplusplus
extern "C" {
#endif

#if !CONFIG_IDF_TARGET_LINUX
#if CONFIG_CONNECT_WIFI
#define NETIF_DESC_STA "the_netif_sta"
#define CONFIG_WIFI_NEED_THIS_FILE 1
#endif

#if CONFIG_WIFI_SCAN_METHOD_FAST
#define WIFI_SCAN_METHOD WIFI_FAST_SCAN
#elif CONFIG_WIFI_SCAN_METHOD_ALL_CHANNEL
#define WIFI_SCAN_METHOD WIFI_ALL_CHANNEL_SCAN
#endif

#if CONFIG_WIFI_CONNECT_AP_BY_SIGNAL
#define WIFI_CONNECT_AP_SORT_METHOD WIFI_CONNECT_AP_BY_SIGNAL
#elif CONFIG_WIFI_CONNECT_AP_BY_SECURITY
#define WIFI_CONNECT_AP_SORT_METHOD WIFI_CONNECT_AP_BY_SECURITY
#endif

#define WIFI_SCAN_AUTH_MODE_THRESHOLD WIFI_AUTH_WPA_WPA2_PSK

/**
 * @brief Configure Wi-Fi or Ethernet, connect, wait for IP
 *
 * This all-in-one helper function is used in protocols examples to
 * reduce the amount of boilerplate in the example.
 *
 * @return ESP_OK on successful connection
 */
esp_err_t wifi_connect(void);

/**
 * Counterpart to example_connect, de-initializes Wi-Fi or Ethernet
 */
esp_err_t wifi_disconnect(void);

/**
 * @brief Configure stdin and stdout to use blocking I/O
 *
 * This helper function is used in ASIO examples. It wraps installing the
 * UART driver and configuring VFS layer to use UART driver for console I/O.
 */
esp_err_t configure_stdin_stdout(void);

/**
 * @brief Returns esp-netif pointer created by example_connect() described by
 * the supplied desc field
 *
 * @param desc Textual interface of created network interface, for example "sta"
 * indicate default WiFi station, "eth" default Ethernet interface.
 *
 */
esp_netif_t *get_netif_from_desc(const char *desc);

#if CONFIG_PROVIDE_WIFI_CONSOLE_CMD
/**
 * @brief Register wifi connect commands
 *
 * Provide a simple wifi_connect command in esp_console.
 * This function can be used after esp_console is initialized.
 */
void register_wifi_connect_commands(void);
#endif


#else
static inline esp_err_t wifi_connect(void) {return ESP_OK;}
#endif // !CONFIG_IDF_TARGET_LINUX

#ifdef __cplusplus
}
#endif
