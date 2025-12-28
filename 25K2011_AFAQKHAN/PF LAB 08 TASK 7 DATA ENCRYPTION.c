#include <stdio.h>

int main() {
    int data[3][3];
    int key[3][3];
    int encrypted[3][3];
    int i, j;
    int maxValue;
    int maxRow = 0, maxCol = 0;

    printf("Enter values for Data matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &data[i][j]);
    }
    }

    printf("\nEnter values for Key matrix:\n");
    for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
        scanf("%d", &key[i][j]);
    }
    }
    for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
    encrypted[i][j] = (data[i][j] * key[i][j]) + (i + j);

    if (i == 0 && j == 0) {
        maxValue = encrypted[i][j];
        maxRow = i;
        maxCol = j;
            }

    else if (encrypted[i][j] > maxValue) {
        maxValue = encrypted[i][j];
            maxRow = i;
            maxCol = j;5
        }
        }
    }

    printf("\nEncrypted Matrix:\n");
    for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
        printf("%d\t", encrypted[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum encrypted value: %d at position [%d][%d]\n", maxValue, maxRow, maxCol);

    return 0;
}

