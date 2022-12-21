#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "led.h"
#include "config_params.h"

void pin_output_config(int output) {
  bcm2835_gpio_fsel(output, BCM2835_GPIO_FSEL_OUTP);
}

void pin_input_config(int input) {
  bcm2835_gpio_fsel(input, BCM2835_GPIO_FSEL_INPT);
  bcm2835_gpio_set_pud(input, BCM2835_GPIO_PUD_UP);
}

short pin_status(int pin) {
  return bcm2835_gpio_lev(pin);
}

void turn_on_or_off_output(int output) {
  if (pin_status(output) == HIGH) {
    bcm2835_gpio_write(output, LOW);
  } else {
    bcm2835_gpio_write(output, HIGH);
  }
}

void handle_interrupt(int signal) {
  bcm2835_close();
  exit(0);
}

void handle_led_config(config_params* params) {
  if (!bcm2835_init()) {
    exit(1);
  }

  for (int i = 0; i < OUTPUT_LENGTH; i++)
    pin_output_config(params->outputs[i].gpio);

  for (int i = 0; i < INPUT_LENGTH; i++)
    pin_input_config(params->inputs[i].gpio);
}

// int main(int argc, char **argv) {
//   if (!bcm2835_init()) {
//     exit(1);
//   }

//   pin_output_config();

//   turn_on_led(LED_1);
//   turn_on_led(LED_2);

//   return 0;
// }