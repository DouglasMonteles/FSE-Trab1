#ifndef _TEMPERATURE_SENSOR_H_
#define _TEMPERATURE_SENSOR_H_

#define ATTEMPTS 15

void config_wiring_pi();
short read_data(int signal);
char* calc_temp(int signal);
void to_string_temp(char* dest, float celsius, float humidity);

#endif