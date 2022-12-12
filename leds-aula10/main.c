#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <bcm2835.h>

// Led's and Button's config
#define LED_1 RPI_V2_GPIO_P1_12 // GPIO 18
#define BOTAO RPI_V2_GPIO_P1_05 // BCM 3

void pin_config(void) {
  // set enter button
  // bcm2835_gpio_fsel(BOTAO, BCM2835_GPIO_FSEL_INPT);

  // set the button as Pull-up
  // bcm2835_gpio_set_pud(BOTAO, BCM2835_GPIO_PUD_UP);

  // set the pins of the led as output
  bcm2835_gpio_fsel(LED_1, BCM2835_GPIO_FSEL_OUTP);
  // bcm2835_gpio_fsel(LED_2, BCM2835_GPIO_FSEL_OUTP);
  // bcm2835_gpio_fsel(LED_4, BCM2835_GPIO_FSEL_OUTP);
  // bcm2835_gpio_fsel(LED_8, BCM2835_GPIO_FSEL_OUTP);
}

void turn_on_led(int led_mask) {
  bcm2835_gpio_write(LED_1, LOW);
//   bcm2835_gpio_write(LED_2, led_mask & 2);
//   bcm2835_gpio_write(LED_4, led_mask & 4);
//   bcm2835_gpio_write(LED_8, led_mask & 8);
}

void handle_interrupt(int signal) {
  turn_on_led(0);
  bcm2835_close();
  exit(0);
}

int main(int argc, char **argv) {
  if (!bcm2835_init()) {
    exit(1);
  }

  pin_config();

  printf("O LED 1 esta: %d\n", bcm2835_gpio_lev(LED_1));

  turn_on_led(1);

  printf("O LED 1 esta: %d\n", bcm2835_gpio_lev(LED_1));

  // signal(SIGINT, handle_interrupt);

  // int counter = 0;

  // while (1) {
  //   counter = 0;

  //   while (counter < 16) {
  //     while (!bcm2835_gpio_lev(BOTAO)) {
  //       printf("Botao reset precionado!\n");
  //       turn_on_led(15);
  //       counter = 0;
  //     }

  //     turn_on_led(counter);

  //     counter++;

  //     delay(1000);
  //   }
  // }

  return 0;
}