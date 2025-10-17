#include <stdio.h>

int main() {
    int d1, d2;
    printf("Enter the 2nd last digit of your student ID: ");
    scanf("%d", &d1);
    printf("Enter the last digit of your student ID: ");
    scanf("%d", &d2);
    int count = 0;
    int num = 1;

    while (count < 10) {
        if (num % d1 == 0 && num % d2 == 0) {
            printf("%d ", num);
            count++;
        }
        num++;
    }

    return 0;
}

