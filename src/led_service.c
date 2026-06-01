#include "led_service.h"
#include "hal_gpio.h"
#include "ble_nus.h"

#include <string.h>
#include "esp_log.h"

static const char *TAG = "LED_SERVICE";

// Callback registrado en el driver — aquí vive la lógica de negocio
static void on_ble_comando(const char *data, uint16_t len)
{
    ESP_LOGI(TAG, "Comando: %s", data);

    if (strncmp(data, "ON", 2) == 0)
    {
        hal_gpio_set(LED_GPIO, 1);
        ble_nus_send("LED encendido");
    }
    else if (strncmp(data, "OFF", 3) == 0)
    {
        hal_gpio_set(LED_GPIO, 0);
        ble_nus_send("LED apagado");
    }
    else
    {
        ble_nus_send("Comando invalido");
    }
}

void led_service_init(void)
{
    // Registra el callback en el driver — el driver llama a on_ble_comando
    // cuando llega un dato, sin saber qué hace con él
    ble_nus_init("ESP32-NUS", on_ble_comando);
}
