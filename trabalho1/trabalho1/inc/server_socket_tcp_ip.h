#ifndef _SERVER_SOCKET_TCP_IP_H_
#define _SERVER_SOCKET_TCP_IP_H_

#include "config_params.h"

short create_server_socket(void);
int bind_created_socket(int new_socket, char* host, int port);
void init_observer_tcp_ip_server_connection(config_params* params);
void send_message_from_server_to_client(int sock);

#endif