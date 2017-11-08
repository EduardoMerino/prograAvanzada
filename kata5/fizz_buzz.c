#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fizz_buzz.h"

char** fizzBuzz(int n){
  char** result = malloc(n * sizeof(char*));
  char* temp;
  char temp2[10];
  int i = 0;
  int len;

  if(n == 0){
    return NULL;
  }

  for(; i < n; i++){
    if(i%3 == 0 && i%5 != 0){
      temp = "Fizz";
    }else if(i%3 != 0 && i%5 == 0){
      temp = "Buzz";
    }else if(i%3 == 0 && i%5 == 0){
      temp = "FizzBuzz";
    }else{
      sprintf(temp2, "%d", i);
      temp = temp2;
    }
    len = strlen(temp);
    result[i] = malloc(len * sizeof(char));
    strcpy(result[i], temp);
    //result[i] = temp;

  }

  return result;

}
