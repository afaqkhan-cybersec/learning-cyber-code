#include <stdio.h>
#include <math.h>  

int main() {
    float loan, annualRate, r, emi;
    int duration, months;

    
    printf("Enter your loan amount: ");
    scanf("%f", &loan);

    printf("Enter your annual interest rate (%%): ");
    scanf("%f", &annualRate);

    printf("Enter loan duration in years: ");
    scanf("%d", &duration);


    months = duration * 12;               
    r = (annualRate / 100.0) / 12;         
    emi = (loan * r * pow(1 + r, months)) / (pow(1 + r, months) - 1);
   
   
    printf("\n===========================\n");
    printf("   LOAN CALCULATION ");
    printf("\n===========================\n");
    printf("LOAN AMOUNT: %.2f\n", loan);
    printf("DURATION: %d years (%d months)\n", duration, months);
    printf("INTEREST RATE: %.2f%% per year\n", annualRate);
    printf("Monthly EMI: %.2f\n", emi);

    return 0;
}
