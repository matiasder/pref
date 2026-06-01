#include "nvs_flash.h"
#include "esp_err.h"
#include "hal_gpio.h"
#include "led_service.h"

void app_main(void)
{
    // NVS requerido por BLE
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES ||
        ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ESP_ERROR_CHECK(nvs_flash_init());
    }

    // HAL
    hal_gpio_init();

    // Service — inicializa BLE internamente y registra callbacks
    led_service_init();
}
