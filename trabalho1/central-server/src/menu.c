#include <stdio.h>
#include "menu.h"

void menu(char *data_send_to_server) {
  // Led
  // handle_led_config();

  printf("-------------MENU--------------\n");
  printf("[1] - Acender/Apagar a Lampada 1 da Sala 1:\n");
  printf("[2] - Acender/Apagar a Lampada 2 da Sala 1:\n");
  printf("[0] - Finalizar o programa\n");
  printf("-------------------------------\n");
  printf("Informe o numero da opcao que voce deseja executar:\n");

  scanf(" %s", data_send_to_server);
  printf("Voce escolheu a opcao: [%s]\n", data_send_to_server);
}