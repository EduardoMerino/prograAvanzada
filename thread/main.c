#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dispatch/dispatch.h>
#define NUM_THREADS     5

//unsigned int total;
dispatch_semaphore_t forks[NUM_THREADS];

void Thinking(int n){
  sleep(rand()%n);
}

void Eating(int n){
  sleep(rand()%n);
}

void *LifeStyle(void *threadid){
  long tid;
  tid = (long)threadid;
  while(1){
    Thinking(3);
    printf("Im the phil #%ld, I'm hungry \n", tid + 1);
    dispatch_semaphore_wait(forks[tid], DISPATCH_TIME_FOREVER);
    dispatch_semaphore_wait(forks[(tid +1) % NUM_THREADS], DISPATCH_TIME_FOREVER);
    Eating(4);
    dispatch_semaphore_signal(forks[tid]);
    dispatch_semaphore_signal(forks[(tid +1) % NUM_THREADS]);
    printf("Im the phil #%ld, I'm thinking\n", tid + 1);
  }
}

/*
void *Add100(void *threadid){
  long tid;
  tid = (long)threadid;
  unsigned int localTotal;
  printf("Adding 100 from thread #%ld!\n", tid + 1);
  dispatch_semaphore_wait(sem1, DISPATCH_TIME_FOREVER);
  localTotal = total;
  localTotal += 100;
  total = localTotal;
  dispatch_semaphore_signal(sem1);
  pthread_exit(NULL);
}

void *PrintHello(void *threadid){
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}
*/

int main (int argc, char *argv[]){
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   //total = 0;
   //sem1 = dispatch_semaphore_create(1);
   //printf("Initial Total: %d\n", total);
   for(t=0; t<NUM_THREADS; t++){
     forks[t] = dispatch_semaphore_create(1);
   }
   for(t=0; t<NUM_THREADS; t++){
      printf("In main: creating thread %ld\n", t + 1);
      rc = pthread_create(&threads[t], NULL, LifeStyle, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
   for(t=0; t<NUM_THREADS; t++){
     pthread_join(threads[t], NULL);
   }
   //printf("Final total: %d\n", total);

   /* Last thing that main() should do */
   pthread_exit(NULL);
}
