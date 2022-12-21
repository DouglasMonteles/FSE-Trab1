#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

// #include "led.h"
// #include "sensor_entrance_exit.h"
  
// void* set_increment(void* arg) {
//   printf("[Info]: Contando a entrada e saida...");

//   int occupation_quantity = *(int*) arg;
//   pthread_detach(pthread_self());

//   while (1) {
//     // Entrance sensor
//     if (pin_status(pin_in)) {
//       occupation_quantity++;
//       printf("Entrada: %d\n", occupation_quantity);
//     }

//     if (pin_status(pin_out)) {
//       if (occupation_quantity > 0)
//         occupation_quantity--;
//       printf("Saida: %d\n", occupation_quantity);
//     }

//     struct timespec tim, tim2;
//     tim.tv_sec = 0;
//     tim.tv_nsec = 300000000L;
//     nanosleep(&tim , &tim2); // 300ms
//   }

//   pthread_exit(NULL);
// }

// void interrupt_threads(int signal) {
//   pthread_exit(NULL);
//   exit(0);
// }
  
// void observer_entrance_exit(int occupation_quantity) {
//   signal(SIGINT, interrupt_threads);

//   pthread_t ptid1;

//   pthread_create(&ptid1, NULL, &set_increment, &occupation_quantity);
//   pthread_exit(NULL);
// }
  
// Driver code
// int main() {
//   signal(SIGINT, handle_interrupt);
  
//   observer_entrance_exit(1,1);

//   return 0;
// }