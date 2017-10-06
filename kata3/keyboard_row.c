#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "keyboard_row.h"

char row1[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
char row2[] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
char row3[] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

/* Is in Row
 * Returns 0 if char is inside the row, else returns 1
 * Reference:
 https://stackoverflow.com/questions/15094834/check-if-a-value-exist-in-a-array
 */
 int isInRow(char val, char* row, int size){
    int i;
    for (i=0; i < size; i++) {
        if (row[i] == val){
          return 0;
        }
    }
    return 1;
}

/* Find Words.
 * Only works with lower case words with the english alphabet
 * no special caractes and worst most be < 9 in length.
 * Input:
 *  words: string array of words to find.
 *  size: size of words array.
 *  returnSize: size of result.
 */
char** findWords(char** words, int size, int returnSize){
  //fix malloc
  //char** result = (char**) malloc(sizeof(char[7]) * returnSize);
  //char** result = (char**) malloc(returnSize * sizeof(*result) + (returnSize * (9 * sizeof(**result))));
  char **result;
  result = (char**) malloc(sizeof(char*) * returnSize);

  int i = 0;
  int j = 0;
  int currWordLen = 0;
  char* currRow;
  int currRowSize;
  int count = 0;

  if(size == 0 || returnSize == 0){
    return NULL;
  }

  for(; i < size; i++){
    j = 0;
    currWordLen = strlen(words[i]);
    if(isInRow(words[i][j], row1, 10) == 0){
      currRow = row1;
      currRowSize = 10;
    }else if(isInRow(words[i][j], row2, 9) == 0){
      currRow = row2;
      currRowSize = 9;
    }else if(isInRow(words[i][j], row3, 7) == 0){
      currRow = row3;
      currRowSize = 7;
    }//else{
      //words[i] = '\0'
    //}

    for(; j < currWordLen; j++){
      if(isInRow(words[i][j], currRow, currRowSize) == 1){
        break;
      }

    }
    if(j == currWordLen) {
        result[count] = strdup(words[i]);
        count++;
    }
  }

  printf("%s\n", result[0]);
  return result;
}
