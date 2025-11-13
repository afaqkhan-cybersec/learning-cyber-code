#include <stdio.h>

float highest_Temperature(float temps[4]);  
int main() {
    float temperatures[5][4];  
    int i, j;

    for (i = 0; i < 5; i++) {
        printf("Enter 4 temperature readings for Patient %d:\n", i + 1);
        for (j = 0; j < 4; j++) {
            scanf("%f", &temperatures[i][j]);
        }
    }
    printf("\nHighest temperatures of each patient:\n");

    for (i = 0; i < 5; i++) {

        float max_Temp = highest_Temperature(temperatures[i]);
        printf("Patient %d: %.2fF", i + 1, max_Temp);

        if (max_Temp > 101) {
            printf(" Temperature above 101F");
        }
        printf("\n");
    }

    return 0;
}

float highest_Temperature(float temps[4]) {
    float max = temps[0];
    int i;
    for ( i = 1; i < 4; i++) {
        max = (temps[i] > max) ? temps[i] : max;
    }
    return max;
}

