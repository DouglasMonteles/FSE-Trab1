#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

#include "client_socket_tcp_ip.h"
#include "server_socket_tcp_ip.h"
#include "menu.h"
#include "config_params.h"
#include "log.h"
#include "sensor_entrance_exit.h"
#include "led.h"

static char occupation[8];
  
void* set_increment(void* arg) {
  while (1) {
    // Entrance sensor
    if (pin_status(pin_in)) {
      occupation_quantity++;
    }

    if (pin_status(pin_out)) {
      if (occupation_quantity > 0)
        occupation_quantity--;
    }

    snprintf(occupation, 8, "%d", occupation_quantity);

    struct timespec tim, tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 300000000L;
    nanosleep(&tim , &tim2); // 300ms
  }
  
  pthread_exit(NULL);
}

void interrupt_threads(int signal) {
  pthread_exit(NULL);
  exit(0);
}

int main(int argc, char** argv) {
  // Initial params
  char type = argv[1][0];

  // Convert config params into a struct config_params
  config_params *params = malloc(sizeof(config_params));

  build_params(params, argv);

  printf("[Info]: Host Central: %s - Port: %d\n", params->ip_servidor_central, params->porta_servidor_central);
  printf("[Info]: Host Distribuido: %s - Port: %d\n", params->ip_servidor_distribuido, params->porta_servidor_distribuido);
  printf("\n");

  handle_led_config(params);

  pin_in = params->inputs[4].gpio;
  pin_out = params->inputs[5].gpio;

	if (type == 'c') { 
    // Central server
    char option[20];
    char* response;

    do {
      response = malloc(sizeof(char) * 50);
      menu(params, option);
      init_observer_tcp_ip_client_connection(params, option, response);

      if (option[0] == '6')
        menu_status_inputs(response, params);

      register_log(menu_opts[(option[0] - '0') - 1], response);

      free(response);
    } while (option[0] != '0');
  } else { 
    // Distributed server
    signal(SIGINT, interrupt_threads);

    pthread_t ptid1;

    pthread_create(&ptid1, NULL, &set_increment, NULL);
    init_observer_tcp_ip_server_connection(params, occupation);
    pthread_join(ptid1, NULL);

    pthread_exit(NULL);
  }

  return 0;
}
