#ifndef _MENU_H_
#define _MENU_H_

#include "config_params.h"

void menu(char* data_send_to_server);
char* menu_options(char opc, config_params* params);
void menu_status_inputs(char* status, config_params* params);

#endif