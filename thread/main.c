#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dispatch/dispatch.h>
#define NUM_THREADS     100

unsigned int total;
dispatch_semaphore_t sem1;

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

int main (int argc, char *argv[]){
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   total = 0;
   sem1 = dispatch_semaphore_create(1);
   printf("Initial Total: %d\n", total);
   for(t=0; t<NUM_THREADS; t++){
      printf("In main: creating thread %ld\n", t + 1);
      rc = pthread_create(&threads[t], NULL, Add100, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
   for(t=0; t<NUM_THREADS; t++){
     pthread_join(threads[t], NULL);
   }
   printf("Final total: %d\n", total);

   /* Last thing that main() should do */
   pthread_exit(NULL);
}
