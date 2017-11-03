#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS     100

unsigned int total;

void *Add100(void *threadid){
  long tid;
  tid = (long)threadid;
  unsigned int localTotal;
  printf("Adding 100 from thread #%ld!\n", tid + 1);
  localTotal = total;
  localTotal += 100;
  sleep(tid%3);
  total = localTotal;
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
