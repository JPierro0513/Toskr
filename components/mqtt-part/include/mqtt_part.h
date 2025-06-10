#pragma once

#include <mqtt_client.h>

#define CONFIG_BROKER_URI  "mqtt://10.0.0.57"
#define CONFIG_BROKER_PORT 1883
#define CONFIG_CLIENT_ID   "Toskr"

void mqtt_app_start(void);

static inline void log_error_if_nonzero(const char *message, int error_code)
{
    if (error_code != 0)
        ESP_LOGE("[mqtt]", "Last error %s: 0x%x", message, error_code);
}

