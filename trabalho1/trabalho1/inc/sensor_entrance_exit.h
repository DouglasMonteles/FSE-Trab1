#ifdef _SENSOR_ENTRANCE_EXIT_
#define _SENSOR_ENTRANCE_EXIT_

void* set_increment(void* arg);
void* set_decrement(void* arg);
void interrupt_threads(int signal);
void observer_entrance_exit(int occupation_quantity, int pin_entrance, int pin_exit);

#endif