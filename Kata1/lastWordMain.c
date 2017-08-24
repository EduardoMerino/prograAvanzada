#include <stdio.h>
#include "lastWord.h"

int main(int argn, char ** argv){
  char * words = "hello world Im Eduardo";
  int len;

  len = getLastWordLen(words);

  printf("%d\n", len);
}
