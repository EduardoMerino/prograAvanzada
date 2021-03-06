#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "single_number.h"
/* Add function signatures here */
int main(int argc, char **argv) {
  /* Start your code here */
  int inputSize, uniqueSize, temp, i, result;
  printf("Single number.\n");
  printf("Give me the size of the array: ");
  scanf("%d", &inputSize);
  if(inputSize == 0 || !(inputSize % 2)){
    printf("the size must be of an odd number.\n");
    return 0;
  }
  uniqueSize = ((inputSize -1 )/ 2) + 1;
  int inputArr[inputSize];
  memset(inputArr, 0, inputSize);

  for(i = 0; i < inputSize; i++){
    printf("Give me the number for position %d :", i);
    scanf("%d", &temp);
    if(temp == 0){
      printf("The array can't contain 0. \n");
      return 0;
    }
    inputArr[i] = temp;
  }

  result = singleNumber(inputArr, inputSize, uniqueSize);
  printf("The single number is : %d\n", result);

  return 0;
}
