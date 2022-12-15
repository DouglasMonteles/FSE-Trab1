#ifndef _CONFIG_PARAMS_H_
#define _CONFIG_PARAMS_H_

#define MAX_IP_LENGTH 16
#define MAX_STR 20
#define OUTPUT_LENGTH 5
#define INPUT_LENGTH 6
#define TAG_LENGTH 3 

struct input_output_params;
struct config_params;

typedef struct input_output_params {
  char type[MAX_STR];
  char tag[MAX_STR];
  int gpio;
} input_output_params;

typedef struct config_params {
  char ip_servidor_central[MAX_IP_LENGTH]; 
  int porta_servidor_central;
  char ip_servidor_distribuido[MAX_IP_LENGTH];
  int porta_servidor_distribuido;
  char nome[MAX_STR];
  input_output_params outputs[5];
  input_output_params inputs[6];
  input_output_params sensor_temperatura;
} config_params;

void print_args(int argc, char** argv);
void build_params(config_params *params, char** argv);

#endif