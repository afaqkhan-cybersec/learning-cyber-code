#include <stdio.h>

void calcdenom(int *denom, int *count, int size, int amount);

int main() {
 int amount; 
 int denom[3] = {5000, 1000, 500};
 int count[3] = {0, 0, 0};
 int i;
 
    printf("Enter the amount of money you want to withdraw: ");
    scanf("%d", &amount);

 if (amount % 50 != 0) {
      printf("Wrong input, Please enter amount that is multiple of 50\n");
        return 0;
    }

    calcdenom(denom, count, 3, amount);

    printf("\nDenomination report:\n");
    for ( i = 0; i < 3; i++) {
        printf("%d notes are: %d\n", denom[i], count[i]);
    }

    return 0;
}

void calcdenom(int *denom, int *count, int size, int amount) {
	int i;
    for (i = 0; i < size; i++) {
        *(count + i) = amount / *(denom + i);
        amount = amount % *(denom + i);
    }
}

