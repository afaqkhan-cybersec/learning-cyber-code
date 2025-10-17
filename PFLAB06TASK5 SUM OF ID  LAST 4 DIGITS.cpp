#include <stdio.h>

int main() {
    int number, digit, sum = 0;
    printf("ENTER THE LAST FOUR DIGITS OF YOUR ID CARD: ");
    scanf("%d", &number);
    while (number != 0) {
        digit = number % 10;
        sum = sum + digit;
        number = number / 10;
    }
    printf("Sum of digits = %d", sum);

    return 0;
}

