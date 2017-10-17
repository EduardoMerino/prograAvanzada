#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "island.h"
/* Add function signatures here */
int main(int argc, char **argv) {
  int columns, rows, i, j, perimeter, buf;
  printf("Welcome to the island perimeter calculator!\n");
  printf("How many columns wide? ");
  scanf("%d", &columns);
  printf("How many rows tall? ");
  scanf("%d", &rows);
  printf("Rows: %d, columns: %d\n", rows, columns);
  //int** map [][]= (int**) malloc(sizeof(int*) * columns);
  int map[rows][columns];
  memset(map, 0, sizeof(map));

  for(i = 0; i < rows; i++){
    for(j = 0; j < columns; j++){
      printf("give me the value of space %d, %d : ", i, j);
      scanf("%d", &buf);
      map[i][j] = buf;
      //memcpy(map[i][j], buf, sizeof(int));
    }
  }
  //needs fix

  printf("The perimeter of your island is: %d\n", islandPerimeter(rows, columns, map));

  return 0;
}
