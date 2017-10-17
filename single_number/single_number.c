#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "single_number.h"

/* Is in Array.
 * Returns the position if number is contained in an array,
 * if not, returns -1.
 * input:
 *  val: value to look for.
 *  arr: the array to be searched in.
 *  size: size of array
 */
int isInArray(int val, int* array, int size){
   int i;
   for (i=0; i < size; i++) {
       if (array[i] == val){
         return i;
       }
   }
   return -1;
}

/* getSingleNumber.
 * returns the only number different from 0 in an array.
 * returns 0 if there is no number.
 * input:
 *  uniqueArray: an array with one number y the rest are ceros.
 *  size: size of  uniqueArray.
 */
int getSingleNumber(int* uniqueArray, int size){
  int i;
  for (i=0; i < size; i++) {
      if (uniqueArray[i] != 0){
        return uniqueArray[i];
      }
  }
  return 0;
}

/* Single Number.
 * Given an array of integers, every element appears twice except for one.
 * Returns that single one.
 * input:
 *  numsArray: array of numbers.
 *  inputSize: size of numsArray.
 *  uniqueSize: amount of unique numbers.
 * Constraints:
 *  numsArray can't contain 0.
 */
int singleNumber(int* numsArray, int inputSize, int uniqueSize){
  int i, uniquePosition, result;
  int nextUnique = 0;
  int uniqueArray[uniqueSize];
  memset(uniqueArray, 0, uniqueSize);

   if (numsArray == NULL){
     return 0;
   }
   if (inputSize == 0 || uniqueSize == 0){
     return 0;
   }

   for(i = 0; i < inputSize; i++){
     uniquePosition = isInArray(numsArray[i], uniqueArray, uniqueSize);
     if(uniquePosition == -1){
       //that number isn't in my uniqueArray, so put it there once.
       uniqueArray[nextUnique] = numsArray[i];
       nextUnique++;
     }else{
       uniqueArray[uniquePosition] = 0;
     }
   }

   result = getSingleNumber(uniqueArray, uniqueSize);

  return result;
}
