#include <stdio.h>

int main() {
    char name[30];
    int unit;
    float priceper_unit;

    printf("Enter your name\n");
    scanf("%s", name);

    printf("Enter your units consumed\n");
    scanf("%d", &unit);

    printf("Enter price per unit\n");
    scanf("%f", &priceper_unit);

    float total_bill = unit * priceper_unit;

    printf("\n======= ELECTRICITY BILL =======\n");
    printf("Customer: %s\n", name);
    printf("Units consumed: %d\n", unit);
    printf("Price per unit: %.2f\n", priceper_unit);
    printf("-------------------------------\n");
    printf("Total bill: %.2f PKR\n", total_bill);
    printf("================================\n");

    return 0;
}
