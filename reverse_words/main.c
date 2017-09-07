#include <stdlib.h>
#include <stdio.h>
#include "reverse_words.h"

/* Add function signatures here */

int main(int argc, char **argv) {
  /* Start your code here */
  char *palabras = reverseWords("hola mundo");
  printf("result: %s \n", palabras);
  return 0;
}
