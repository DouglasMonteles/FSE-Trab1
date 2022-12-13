#include "server_socket_tcp_ip.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char* host = argv[1];
	int port = atoi(argv[2]);

	printf("[Info]: Host: %s\n", host);
	printf("[Info]: Port: %d\n", port);
	printf("\n");

	init_observer_tcp_ip_server_connection(host, port);

	return 0;
}