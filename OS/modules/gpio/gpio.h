#ifndef _GPIO_H
#define _GPIO_H

#include "peripherals/gpio.h"

#define      INPUT                 0
#define      OUTPUT                1

#define      GPIO_MAX_PIN         53

#define      PULL_NONE             0
#define      PULL_DOWN             1
#define      PULL_UP               2


#define      LED_RED_GPIO5         5

#define      LED_BLUE_GPIO6        6

#define      LED_WHITE_GPIO26    26



extern gpio_t* get_gpio(void);


void gpio_init();
unsigned int gpio_pin_configure(unsigned int pin, int function);
void gpio_pin_on(unsigned int  pin);
void gpio_pin_off(unsigned int pin);
unsigned int  gpio_get_value(unsigned int pin);
unsigned int gpio_pin_trigger(unsigned int pin, unsigned int  pull);
void gpio_toggle_pin(unsigned int pin);


#endif