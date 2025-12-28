#include <stdio.h>

int main() {
    int img[5][5];
	int sharp[5][5];
    int i, j;
    float sum_before = 0;
	float sum_after = 0;

    printf("Enter 5x5 image pixel values (0-255):\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &img[i][j]);
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            sum_before += img[i][j];
            sharp[i][j] = img[i][j] * 2;
            if (sharp[i][j] > 255)
                sharp[i][j] = 255;
            sum_after += sharp[i][j];
	  
     }
  }
    printf("\nSharpened Image:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%3d ", sharp[i][j]);
        }
        printf("\n");
    }
    printf("\nAverage intensity before: %.2f", sum_before / 25);
    printf("\nAverage intensity after: %.2f\n", sum_after / 25);

    return 0;
}

