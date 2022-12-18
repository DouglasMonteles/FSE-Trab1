#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "client_socket_tcp_ip.h"
#include "server_socket_tcp_ip.h"
#include "menu.h"
#include "config_params.h"

int main(int argc, char** argv) {
  // Initial params
  char type = argv[1][0];

  // Convert config params into a struct config_params
  config_params *params = malloc(sizeof(config_params));

  print_args(argc, argv);
  build_params(params, argv);

  printf("[Info]: Host Central: %s - Port: %d\n", params->ip_servidor_central, params->porta_servidor_central);
  printf("[Info]: Host Distribuido: %s - Port: %d\n", params->ip_servidor_distribuido, params->porta_servidor_distribuido);
  printf("\n");

	if (type == 'c') { 
    // Central server
    char option[20];
    char* response;

    do {
      response = malloc(sizeof(char) * 50);
      menu(option);
      init_observer_tcp_ip_client_connection(params, option, response);

      if (option[0] == '6')
        menu_status_inputs(response, params);

      free(response);
    } while (option[0] != '0');
  } else { 
    // Distributed server
	  init_observer_tcp_ip_server_connection(params);
  }

  return 0;
}
