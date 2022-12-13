#ifndef _LED_H_
#define _LED_H_

#include <bcm2835.h>

// Led's and Button's config
#define LED_1 RPI_V2_GPIO_P1_12 // GPIO 18
#define LED_2 RPI_V2_GPIO_P1_16 // GPIO 23

void pin_config(void);
short led_status(int led);
void turn_on_or_off_led(int led);
void handle_interrupt(int signal);

#endif