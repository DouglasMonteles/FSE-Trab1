#include <stdio.h>
#include <string.h>

#include "menu.h"
#include "config_params.h"
#include "led.h"
#include "temperature_sensor.h"

char str_response[50];
int room;
char ips[4][20] = {
  "192.168.1.134", 
  "192.168.1.146", 
  "192.168.1.132", 
  "192.168.1.129"
};

// Central server
void menu(config_params* params, char *data_send_to_server) {
  // Led
  // handle_led_config();
  printf("Informe o numero da sala [1] | [2] | [3] | [4] (apenas o numero): \n");
  scanf("%d", &room);

  strcpy(params->ip_servidor_central, ips[room-1]);

  printf("\n-------------------MENU--------------------\n");
  
  for (int i = 0; i < MAX_OPTIONS; i++) {
    printf("[%d]: %s\n", (i+1), menu_opts[i]);
  }

  printf("-------------------------------------------\n");
  printf("Informe o numero da opcao que voce deseja executar:\n");

  scanf(" %s", data_send_to_server);
  printf("Voce escolheu a opcao: [%s]\n", data_send_to_server);
}

// Distributed server
char* menu_options(char opc, config_params* params) {
  char input_status[6];
  char aux[10];

  switch (opc) {
		case '1':
			turn_on_or_off_output(params->outputs[0].gpio);
      return "Output acionado!";

		case '2':
			turn_on_or_off_output(params->outputs[1].gpio);
			return "Output acionado!";
    
    case '3':
			turn_on_or_off_output(params->outputs[2].gpio);
			return "Output acionado!";
    
    case '4':
			turn_on_or_off_output(params->outputs[3].gpio);
			return "Output acionado!";
    
    case '5':
			turn_on_or_off_output(params->outputs[4].gpio);
			return "Output acionado!";

    case '6':
      for (int i = 0; i < INPUT_LENGTH; i++) {
        int pin = params->inputs[i].gpio;
        input_status[i] = pin_status(pin) + '0'; // convert short to char
      }

      strcpy(str_response, input_status);
      return str_response;

    case '7':
      strcpy(str_response, calc_temp(params->sensor_temperatura.gpio));
      return str_response;

    case '8':
      str_response[0] = '\0';
      snprintf(aux, 10, "%d", occupation_quantity);
      strcat(str_response, "Ocupacao da sala: ");
      strcat(str_response, aux);
      return str_response;
		
		default:
			break;
		}
}

void menu_status_inputs(char* status, config_params* params) {
  for (int i = 0; i < INPUT_LENGTH; i++)
    printf("A entrada [%s] esta: [%s]\n", params->inputs[i].tag, (status[i] == '1') ? "Ativa" : "Inativa");
  printf("\n");
}