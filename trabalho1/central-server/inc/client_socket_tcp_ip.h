#ifndef _CLIENT_INSTANCE_H_
#define _CLIENT_INSTANCE_H_

short create_client_socket(void);
int connect_client_socket(int socket_created, char *host, int port);
int send_data_through_socket(int socket_created, char *host_request, short size_request);
int receive_data_through_socket(int socket_created, char *host_request, short request_size);
void destroy_client_socket(int created_client_socket);
int init_observer_tcp_ip_client_connection(char* host, int port, char* msg);
void send_message_to_client(int created_client_socket, char* host, int port, char* msg);

#endif