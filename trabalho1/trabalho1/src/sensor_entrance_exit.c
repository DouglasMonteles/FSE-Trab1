#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

#include "led.h"
#include "sensor_entrance_exit.h"

int pin_in, pin_out;
  
void* set_increment(void* arg) {
  int occupation_quantity = *(int*) arg;
  printf("arg: %d\n", occupation_quantity);
  pthread_detach(pthread_self());

  printf("Inside the thread\n");

  while (1) {
    // Entrance sensor
    while (pin_status(pin_in)) {
      occupation_quantity++;
      //printf("Entrada: %d\n", occupation_quantity);
      sleep(0.300); // 300 microseconds
    }
  }

  pthread_exit(NULL);
}

void* set_decrement(void* arg) {
  int occupation_quantity = *(int*) arg;
  pthread_detach(pthread_self());

  printf("Inside the thread 2\n");

  while (1) {
    // Exit sensor
    while (pin_status(pin_out)) {
      if (occupation_quantity > 0)
        occupation_quantity-=5;
      // printf("Saida: %d\n", occupation_quantity);
      sleep(0.300); // 300 microseconds
    }
  }

  pthread_exit(NULL);
}

void interrupt_threads(int signal) {
  pthread_exit(NULL);
  exit(0);
}
  
void observer_entrance_exit(int occupation_quantity, int pin_entrance, int pin_exit) {
  signal(SIGINT, interrupt_threads);

  pthread_t ptid1;
  pthread_t ptid2;

  pin_in = pin_entrance;
  pin_out = pin_exit;

  pthread_create(&ptid1, NULL, &set_increment, &occupation_quantity);
  pthread_create(&ptid2, NULL, &set_decrement, &occupation_quantity);
  printf("This line may be printed before thread terminates\n");
  printf("Occupation: %d\n", occupation_quantity);

  pthread_join(ptid1, NULL);
  pthread_join(ptid2, NULL);
  printf("This line will be printed after thread ends\n");

  pthread_exit(NULL);
}
  
// Driver code
// int main() {
//   signal(SIGINT, handle_interrupt);
  
//   observer_entrance_exit(1,1);

//   return 0;
// }