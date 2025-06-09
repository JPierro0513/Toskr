idf_component_register(SRCS "connection.c"
                       INCLUDE_DIRS "include"
                       REQUIRES mqtt nvs_flash wifi_sta)
