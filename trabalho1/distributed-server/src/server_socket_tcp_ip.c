#include "server_socket_tcp_ip.h"
#include "led.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

short create_server_socket(void) {
	short new_socket;
	printf("[Info]: Creating the socket\n");
	new_socket = socket(AF_INET, SOCK_STREAM, 0);

	return new_socket;
}

int bind_created_socket(int new_socket, char* host, int port) {
	int is_socket_bound = -1;
	struct sockaddr_in remote = { 0 };
	
	remote.sin_family = AF_INET; 													// Internet address family
	remote.sin_addr.s_addr = inet_addr(host); 						// Any incoming interface
	remote.sin_port = htons(port); 												// Local port
	is_socket_bound = bind(new_socket, (struct sockaddr *)&remote, sizeof(remote));
	
	return is_socket_bound;
}

void init_observer_tcp_ip_server_connection(char* host, int port) {
	struct sockaddr_in server, client;

	int socket_created, sock, client_msg_size, read_size;
	char client_message[200]= {0};
	char message[100] = { 0 };

	const char *pMessage = "hello";

	// Create socket
	socket_created = create_server_socket();

	if (socket_created == -1) {
		printf("[Error]: Could not create socket");
		exit(1);
	}

	printf("[Success]: Socket created\n");

	// Bind
	if (bind_created_socket(socket_created, host, port) < 0) {
		//print the error message
		perror("[Error]: bind failed.");
		exit(1);
	}

	printf("[Success]: bind done\n");

	// Listen
	if (listen(socket_created, 3) < 0) {
		printf("[Error]: Listen created socket returned error.\n");
		exit(1);
	}

	// Accept and incoming connection
	while(1) {
		printf("[Info]: Waiting for incoming connections...\n");
		client_msg_size = sizeof(struct sockaddr_in);

		// accept connection from an incoming client
		sock = accept(socket_created, (struct sockaddr *)&client, (socklen_t*)&client_msg_size);
		if (sock < 0) {
			perror("[Error]: Accept failed");
			exit(1);
		}

		printf("[Success]: Connection accepted\n");
		memset(client_message, '\0', sizeof client_message);
		memset(message, '\0', sizeof message);

		// Receive a reply from the client
		if (recv(sock, client_message, 200, 0) < 0) {
			printf("[Error]: recv failed");
			break;
		}

		printf("[Info]: Client reply : %s\n", client_message);

		printf("Comando [%s] recebido!\n", client_message);

		switch (client_message[0]) {
		case '1':
			handle_led_config();
			turn_on_or_off_led(LED_1);
			break;

		case '2':
			handle_led_config();
			turn_on_or_off_led(LED_2);
			break;
		
		default:
			break;
		}

		//if (strcmp(pMessage, client_message) == 0) {
    strcpy(message, "Hi there !");

		// Send some data
		if (send(sock, message, strlen(message), 0) < 0) {
			printf("[Error]: Send failed");
			exit(1);
		}

		close(sock);
		sleep(1);
	}
}