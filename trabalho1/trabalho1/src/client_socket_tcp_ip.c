#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#include "config_params.h"
#include "client_socket_tcp_ip.h"

// Create a Socket for server communication
short create_client_socket(void) {
	short new_socket;
	printf("[Info]: Create the socket\n");
	new_socket = socket(AF_INET, SOCK_STREAM, 0);

	return new_socket;
}

// try to connect with server
int connect_client_socket(int socket_created, char *host, int port) {
	int is_socket_connected = -1;
	struct sockaddr_in remote = { 0 };

	remote.sin_addr.s_addr = inet_addr(host); // Local Host
	remote.sin_family = AF_INET;
	remote.sin_port = htons(port);
	is_socket_connected = connect(socket_created, (struct sockaddr *)&remote, sizeof(struct sockaddr_in));
	
	return is_socket_connected;
}

// Send the data to the server and set the timeout of 20 seconds
int send_data_through_socket(int socket_created, char *host_request, short size_request) {
	int is_data_sended = -1;
	struct timeval tv;

	tv.tv_sec = 20; // 20 Secs Timeout
	tv.tv_usec = 0;
	
	if (setsockopt(socket_created, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0) {
		printf("[Error]: Time Out\n");
		exit(1);
	}

	is_data_sended = send(socket_created, host_request, size_request, 0);
	return is_data_sended;
}

// receive the data from the server
int receive_data_through_socket(int socket_created, char *host_request, short request_size) {
	int is_data_received = -1;
	struct timeval tv;
	
	tv.tv_sec = 20; // 20 Secs Timeout
	tv.tv_usec = 0;

	if (setsockopt(socket_created, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0) {
		printf("Time Out\n");
		exit(1);
	}

	is_data_received = recv(socket_created, host_request, request_size, 0);
	printf("Response %s\n", host_request);

	return is_data_received;
}

void destroy_client_socket(int created_client_socket) {
	close(created_client_socket);
	shutdown(created_client_socket, 0);
	shutdown(created_client_socket, 1);
	shutdown(created_client_socket, 2);
}

void send_message_to_client(int created_client_socket, char* host, int port, char* data_send_to_server) {
	// char data_send_to_server[100] = { 0 };
	char data_received_from_server[200] = { 0 };

	int read_size;

	// Connect to remote server
	if (connect_client_socket(created_client_socket, host, port) < 0) {
		perror("[Error]: Connection to remote server failed.\n");
		exit(1);
	}

	printf("[Success]: Successfully connected with server\n\n");
	// printf("[Info]: Enter the Message: ");

	// fgets(data_send_to_server, sizeof(data_send_to_server), stdin);

	// Send data to the server
	send_data_through_socket(created_client_socket, data_send_to_server, strlen(data_send_to_server));

	// Received the data from the server
	read_size = receive_data_through_socket(created_client_socket, data_received_from_server, 200);
	printf("[Info]: Server Response : %s\n\n", data_received_from_server);
	
	destroy_client_socket(created_client_socket);
}

int init_observer_tcp_ip_client_connection(config_params* params, char* msg) {
	int created_client_socket;
	struct sockaddr_in server;

	// Create socket
	created_client_socket = create_client_socket();

	if (created_client_socket == -1) {
		printf("[Error]: Could not create socket\n");
		exit(1);
	}

	printf("[Success]: Socket is created\n");

	send_message_to_client(created_client_socket, params->ip_servidor_central, params->porta_servidor_central, msg);
}