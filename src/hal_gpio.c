#include "hal_gpio.h"

void hal_gpio_init(void)
{
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(LED_GPIO, 0);
}

void hal_gpio_set(gpio_num_t pin, uint8_t level)
{
    gpio_set_level(pin, level);
}
