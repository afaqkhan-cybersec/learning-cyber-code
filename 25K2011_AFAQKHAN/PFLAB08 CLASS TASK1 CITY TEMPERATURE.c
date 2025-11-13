#include <stdio.h>
int main() {
    float temp[5][7];
    float avg[5];
    int i, j, city_highest = 0;
    float sum, max_avg = 0;
    for (i = 0; i < 5; i++) {
        printf("Enter temperatures for City %d:\n", i + 1);
        for (j = 0; j < 7; j++) {
        scanf("%f", &temp[i][j]);
     }
    }
    for (i = 0; i < 5; i++) {
        sum = 0;
        for (j = 0; j < 7; j++) {
            sum += temp[i][j];
        }
        avg[i] = sum / 7;
        if (avg[i] > max_avg) {
            max_avg = avg[i];
            city_highest = i;
        }
    }
    printf("\nAverage temperatures:\n");
    for (i = 0; i < 5; i++) {
        printf("City %d: %.2f\n", i + 1, avg[i]);
    }

    printf("\nCity %d has the highest average temperature = %.2f\n", city_highest + 1, max_avg);
    return 0;
}

