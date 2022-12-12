#include "client_socket_tcp_ip.h"

#include <stdio.h>
#include <stdlib.h>

// main driver program
int main(int argc, char *argv[]) {
	char* host = argv[1];
	int port = atoi(argv[2]);

	printf("[Info]: Host: %s\n", host);
	printf("[Info]: Port: %d\n", port);
	printf("\n");

	//int socket = init_observer_tcp_ip_client_connection(host, port);
	init_observer_tcp_ip_client_connection(host, port);
	
	return 0;
}