#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include "driver/gpio.h"

#define LED_GPIO 18

void hal_gpio_init(void);
void hal_gpio_set(gpio_num_t pin, uint8_t level);

#endif
