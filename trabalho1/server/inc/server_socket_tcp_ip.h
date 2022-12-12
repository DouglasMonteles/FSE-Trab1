#ifndef _SERVER_SOCKET_TCP_IP_H_
#define _SERVER_SOCKET_TCP_IP_H_

short create_server_socket(void);
int bind_created_socket(int new_socket, char* host, int port);
void init_observer_tcp_ip_server_connection(char* host, int port);
void send_message_from_server_to_client(int sock);

#endif