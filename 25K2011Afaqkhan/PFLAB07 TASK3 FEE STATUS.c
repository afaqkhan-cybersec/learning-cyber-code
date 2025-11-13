#include <stdio.h>

int main() {
    int fee_status[15];
    int delay[15];
    int fine[15];
    int total_fine = 0;
    int i;
    for (i = 0; i < 15; i++) {
        printf("Student %d:\n", i + 1);
        printf("enter fee status (0 for not paid, 1 for paid): ");
        scanf("%d", &fee_status[i]);

        if (fee_status[i] == 0) {
            printf("Enter number of months late in paying fee ");
            scanf("%d", &delay[i]);

            if (delay[i] == 1){
                fine[i] = 500;
            }
            else if (delay[i] >= 2){
                fine[i] = 1000;
			}
			else
                fine[i] = 0; 
        } 
		else {
            delay[i] = 0;
            fine[i] = 0; 
        } 

        total_fine =total_fine+fine[i];
    }
    printf("\n----------------------------------------------------\n");
    printf("Student\tStatus\t\tDelay(months)\tFine\tRemarks\n");
    printf("------------------------------------------------------\n");

    for (i = 0; i < 15; i++) {
        printf("%d\t", i + 1);
        printf("%d\t\t", fee_status[i]);
        printf("%d\t\t", delay[i]);
        printf("%d\t\t", fine[i]);

        if (fee_status[i] == 1)
            printf("cleared\n");
        else
            printf("defaulter\n");
    }

    printf("------------------------------------------------------\n");
    printf("Total fine is: %d\n", total_fine);

    return 0;
}

