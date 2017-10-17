#include <stdlib.h>
#include <stdio.h>
#include "island.h"

int islandPerimeter(int rows, int columns, int map[rows][columns]){
  int perimeter = 0;
  int i, j;

  if(map == NULL){
    printf("ERROR, null map\n");
    return 0;
  }
  if((rows == 0) || (columns == 0)){
    printf("ERROR, cero rows/colums\n");
    return  0;
  }

  for(i = 0; i < rows; i++){
    for(j = 0; j < columns; j++){
      if(map[i][j] == 1){
        perimeter += 4;

        //check north neighbour
        if(i > 0){
          if(map[i - 1][j] == 1){
            perimeter --;
          }
        }

        //check west neighbour
        if(j > 0){
          if(map[i][j - 1] == 1){
            perimeter --;
          }
        }

        //check east neighbour
        if(j < columns - 1){
          if(map[i][j + 1] == 1){
            perimeter --;
          }
        }

        //check south neighbour
        if(i < rows - 1){
          if(map[i + 1][j] == 1){
            perimeter --;
          }
        }

      }
    }
  }

  return perimeter;
}
