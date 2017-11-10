#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "texto.h"

/* in a file we can:
 * Create.
 * Add.
 * Update.
 */
int main(int argc, char **argv) {
  FILE *myFile;
  assert(argc == 2);
  myFile = fopen(argv[1], "r");
  assert(myFile != NULL);

  int temperature = 0, count = 0;
  double average = 0.0;
  while(fscanf(myFile, "temp %d\n", &temperature) != 0){
    if(feof(myFile)){
      break;
    }
    if(count == 0){
      average = temperature;
      count = 1;
    }else{
      average = (average * count) + temperature;
      count++;
      average /= count;
    }
    printf("temp = %d\n", temperature);
    //putchar(toupper(c));
  }
  printf("the average is: %f\n", average);
  fclose(myFile);
  return 0;
}
