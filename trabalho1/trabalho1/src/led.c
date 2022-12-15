#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "led.h"
#include "config_params.h"

void pin_config(int output) {
  bcm2835_gpio_fsel(output, BCM2835_GPIO_FSEL_OUTP);
}

short led_status(int led) {
  return bcm2835_gpio_lev(led);
}

void turn_on_or_off_led(int led) {
  if (led_status(led) == HIGH) {
    bcm2835_gpio_write(led, LOW);
  } else {
    bcm2835_gpio_write(led, HIGH);
  }
}

void handle_interrupt(int signal) {
  turn_on_or_off_led(0);
  bcm2835_close();
  exit(0);
}

void handle_led_config(config_params* params) {
  if (!bcm2835_init()) {
    exit(1);
  }

  for (int i = 0; i < OUTPUT_LENGTH; i++)
    pin_config(params->outputs[i].gpio);
}

// int main(int argc, char **argv) {
//   if (!bcm2835_init()) {
//     exit(1);
//   }

//   pin_config();

//   turn_on_led(LED_1);
//   turn_on_led(LED_2);

//   return 0;
// }