#include <stdio.h>
#include <stdlib.h>

int * getIndexes(int * nums, int len, int target){
  int i, j;
  int candidate;
  int complement;
  int * result = (int *) calloc(2, sizeof(int));

  for(i = 0; i < len - 1; i++){
    int candidate = nums[i];
    if(candidate >= target){
      continue;
    }
    complement = target - candidate;
    for(j = i + 1; j < len; j++){
      if(nums[j] == complement){
        break;
      }
    }
    if(nums[i] + nums[j] == target){
      result[0] = i;
      result[1] = j;
      return result;
    }
  }

  return NULL;
}

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
