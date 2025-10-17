#include <stdio.h>

int main() {
    int num, original;
    long long fact = 1;

    printf("Enter the sum of your last two digits: ");
    scanf("%d", &num);
    original = num;

   while (num>1) {
        fact = fact * num;
        num--;
    }

    printf("Factorial of %d is= %lld\n", original, fact);

    return 0;
}

