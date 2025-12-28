#include <stdio.h>

int main() {
    int grid[3][3];
    int i, j;
    int valid = 1;
    for (i = 0; i < 3; i++) {
    	    printf("Enter numbers for row %d: 0f the grid (use 0 for empty):\n",i+1);
        for (j = 0; j < 3; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] != 0 && (grid[i][j] < 1 || grid[i][j] > 9)) {
        printf("Invalid grid (wrong entery found)\n");
        return 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
     for (j = 0; j < 3; j++) {
        if (grid[i][j] != 0) {
  	int x,y;
          for (x = 0; x < 3; x++) {
           for (y = 0; y < 3; y++) {
                    if ((i != x || j != y) && grid[i][j] == grid[x][y]) {
        printf("Invalid Grid (duplicate found)\n");
            return 0;
                 }
            }
         }
        }
     }
    }
    printf("Valid grid\n");
    return 0;
}

