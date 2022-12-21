/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


int num = 9;
int* x;
pthread_t ptid1;
int aux;

void teste() {
  while(1) {
    printf("%d\n", num);
    sleep(1);
  }
}

void* set_increment(void* arg) {
    while (1) {
        num = num + 1;
        x = &num;
        sleep(1);
    }
}

int main()
{
    pthread_create(&ptid1, NULL, &set_increment, NULL);
    teste();
    pthread_join(ptid1, NULL);
    
    
    printf("Hello World %d\n", aux);

    return 0;
}
