#include <string.h>
#include "lastWord.h"

int getLastWordLen(char * words){

  int length;
  length = strlen(words);
  //length  = sizeof(words) / sizeof(words[0]);
  //printf("%s\n", words);
  //printf("lenght : %d\n", length);

  int count = 0;
  for (int i = length - 1; i > 0; i--) {
    if (words[i] == ' '){
      break;
    }
    count ++;
  }

  return count;
}
