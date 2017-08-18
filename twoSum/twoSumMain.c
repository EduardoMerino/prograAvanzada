#include <stdio.h>
#include "twoSum.h"

int main(int argn, char ** argv){
  int nums[] = {2, 7, 11, 15};
  int target = 9;
  int * result = getIndexes(nums, 4, target);

  printf("\n");
  if(result != NULL && (nums[result[0]] + nums[result[1]] == target)){
    printf("IT WORKS!\n");
  }else{
    printf(":(\n");
  }
}
