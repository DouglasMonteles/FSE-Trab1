#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

#include "log.h"

void date_time(char* date_time_str) {
  char day[4];
  char month[4];
  char year[8];

  char hour[4];
  char minute[4];
  char second[4];

  struct tm *data_hora_atual;     
  
  time_t segundos;
  time(&segundos);   
  
  data_hora_atual = localtime(&segundos);  

  snprintf(day, 4, "%d", data_hora_atual->tm_mday);
  snprintf(month, 4, "%d", data_hora_atual->tm_mon+1);
  snprintf(year, 8, "%d", data_hora_atual->tm_year+1900);

  snprintf(hour, 4, "%d", data_hora_atual->tm_hour);
  snprintf(minute, 4, "%d", data_hora_atual->tm_min);
  snprintf(second, 4, "%d", data_hora_atual->tm_sec);

  strcat(date_time_str, day);
  strcat(date_time_str, "/");
  strcat(date_time_str, month);
  strcat(date_time_str, "/");
  strcat(date_time_str, year);

  strcat(date_time_str, " ");

  strcat(date_time_str, hour);
  strcat(date_time_str, ":");
  strcat(date_time_str, minute);
  strcat(date_time_str, ":");
  strcat(date_time_str, second); 
}

void register_log(const char* command, char* response) {
  FILE *file = fopen("logs.csv", "a");
  char date_time_str[50];

  date_time(date_time_str);

  fprintf(file, "%s,%s,%s", command, response, date_time_str);
  fprintf(file, "%s", "\n");
  fclose(file);
}