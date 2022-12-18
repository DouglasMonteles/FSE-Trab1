#include <stdio.h>
#include <string.h>

#include "menu.h"
#include "config_params.h"
#include "led.h"
#include "temperature_sensor.h"

char str_response[50];

// Central server
void menu(char *data_send_to_server) {
  // Led
  // handle_led_config();

  printf("-------------------MENU--------------------\n");
  printf("[1] - Acender/Apagar a Lampada 1 da Sala 1:\n");
  printf("[2] - Acender/Apagar a Lampada 2 da Sala 1:\n");
  printf("[3] - Ligar/Desligar o Projetor Multimidia:\n");
  printf("[4] - Ligar/Desligar o Ar-Condicionado:\n");
  printf("[5] - Ligar/Desligar o Alarme (sirene / buzzer):\n");
  printf("[6] - Visualizar status dos sensores:\n");
  printf("[7] - Visualizar temperatura:\n");
  printf("[0] - Finalizar o programa\n");
  printf("-------------------------------------------\n");
  printf("Informe o numero da opcao que voce deseja executar:\n");

  scanf(" %s", data_send_to_server);
  printf("Voce escolheu a opcao: [%s]\n", data_send_to_server);
}

// Distributed server
char* menu_options(char opc, config_params* params) {
  char input_status[6];
  
  handle_led_config(params);

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
		
		default:
			break;
		}
}

void menu_status_inputs(char* status, config_params* params) {
  for (int i = 0; i < INPUT_LENGTH; i++)
    printf("A entrada [%s] esta: [%s]\n", params->inputs[i].tag, (status[i] == '1') ? "Ativa" : "Inativa");
  printf("\n");
}