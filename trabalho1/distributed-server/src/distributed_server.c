#include "server_socket_tcp_ip.h"
#include "led.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char* host = argv[1];
	int port = atoi(argv[2]);

	printf("[Info]: Host: %s\n", host);
	printf("[Info]: Port: %d\n", port);
	printf("\n");

	init_observer_tcp_ip_server_connection(host, port);

	// LEDs
	if (!bcm2835_init()) {
    exit(1);
  }

  pin_config();

  turn_on_or_off_led(LED_1);
  turn_on_or_off_led(LED_2);

	return 0;
}