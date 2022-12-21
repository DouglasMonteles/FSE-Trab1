#include "config_params.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void print_args(int argc, char** argv) {
  for (int i = 2; i < argc; i++)
    printf("[%d]: %s\n", i, argv[i]);
}

void build_params(config_params *params, char** argv) {
  strcpy(params->ip_servidor_central, argv[2]);
  params->porta_servidor_central = atoi(argv[3]);
  strcpy(params->ip_servidor_distribuido, argv[4]);
  params->porta_servidor_distribuido = atoi(argv[5]);

  for (int i = 7, j = 0; i < 21, j < OUTPUT_LENGTH; j++) {
    strcpy(params->outputs[j].type, argv[i++]);
    strcpy(params->outputs[j].tag, argv[i++]);
    params->outputs[j].gpio = atoi(argv[i++]);
  }

  for (int i = 22, j = 0; i < 39, j < INPUT_LENGTH; j++) {
    strcpy(params->inputs[j].type, argv[i++]);
    strcpy(params->inputs[j].tag, argv[i++]);
    params->inputs[j].gpio = atoi(argv[i++]);
  }

  strcpy(params->sensor_temperatura.type, argv[40]);
  strcpy(params->sensor_temperatura.tag, argv[41]);
  params->sensor_temperatura.gpio = atoi(argv[42]);
}