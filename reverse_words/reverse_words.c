#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "reverse_words.h"

/* Reverse Words
 * given list of words, reverse the individual words while
 * maintaining order.
 * @param:
 *  words: char* of words.
 *  can't be too large due to malloc restrictions.
 * @return:
 * char*: words inverted but with the same order.
 */
char* reverseWords(char* words){
  int limInf = 0, limSup = 0;
  int length = strlen(words);
  char *buff = (char*) malloc(sizeof(char) * length + 1);

  if(words == NULL || length == 0){
    return "0";
  }

  for (int i = 0; i < length; i++) {

    if (words[i] == ' ' || i == length - 1){
      limSup = i;
      int r = 0;
      if(words[i] == ' '){
        r ++;
      }

      for(int k = limInf; k <= limSup; k++){
        buff[k] = words[limSup - r];
        r++;
      }
      if(words[i] == ' '){
        buff[limSup] = ' ';
      }
      limInf = limSup + 1;
    }

  }
  buff[length] = '\0';

  return (char*) buff;
}
