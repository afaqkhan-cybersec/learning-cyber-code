#include <stdio.h>

int main() {
    int arr[5][5];
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j <= i; j++) {
        arr[i][j] = (i + 1) * (j + 1);
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 3; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
          printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

