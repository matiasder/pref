#ifndef BLE_NUS_H
#define BLE_NUS_H

#include <stdint.h>
#include <stdbool.h>

// Callback que se llama cuando llega un comando por BLE
// El driver no sabe qué hacer con el comando, eso lo decide el service
typedef void (*ble_nus_rx_cb_t)(const char *data, uint16_t len);

void ble_nus_init(const char *device_name, ble_nus_rx_cb_t rx_callback);
void ble_nus_send(const char *msg);
bool ble_nus_connected(void);

#endif
