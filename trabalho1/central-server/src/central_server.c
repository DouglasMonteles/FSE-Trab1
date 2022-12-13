#include "client_socket_tcp_ip.h"
#include "menu.h"

#include <stdio.h>
#include <stdlib.h>

// main driver program
int main(int argc, char *argv[]) {
	// TCP/IP
	char* host = argv[1];
	int port = atoi(argv[2]);

	printf("[Info]: Host: %s\n", host);
	printf("[Info]: Port: %d\n", port);
	printf("\n");

	//int socket = init_observer_tcp_ip_client_connection(host, port);
	char option[20];

	do {
		menu(option);
		init_observer_tcp_ip_client_connection(host, port, option);
	} while (option[0] != '0');
	// ----------------------------------------------------------------
	
	return 0;
}