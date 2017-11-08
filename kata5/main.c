#include <stdlib.h>
#include <stdio.h>
#include "fizz_buzz.h"
/* Add function signatures here */
int main(int argc, char **argv) {
  /* Start your code here */
  int n;
  printf("Welcome to FizzBuzz!\n");
  printf("How numbers to FizzBuzz: ");
  scanf("%d", &n);
  char** res = fizzBuzz(n);
  int i = 0;
  for(; i < n; i++){
    printf("%s\n", res[i]);
  }
  return 0;
}
