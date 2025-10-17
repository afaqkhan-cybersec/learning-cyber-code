#include <stdio.h>
#include <math.h>

int main() {
    int principal = 1000;
    float rate = 0.05;
    int year;
    for (year = 1; year <= 10; year++) {
        float amount=principal*pow(1+0.05,year);
        printf("%d\t%.2f\n", year, amount);
    }
    return 0;
}

