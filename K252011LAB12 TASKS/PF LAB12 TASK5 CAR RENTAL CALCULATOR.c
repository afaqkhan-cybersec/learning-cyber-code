#include <stdio.h>
#include <stdlib.h>

 typedef struct {
    int rental_duration;
    float cost_per_unit;
     float total_cost;
 } Rental;

 int main() {
     int count,add_more,i;

       printf("Enter number of initial rentals");
      scanf("%d", &count);

      Rental *rentals = (Rental *)malloc(count * sizeof(Rental));
      if (rentals==NULL) {
        printf("Memory allocation failed!\n");
           return 1;
      }

    for (i=0;i<count;i++) {
        printf("\n--- Rental %d ---\n",i + 1);
         printf("Enter rental duration (hours/days): ");
          scanf("%d", &rentals[i].rental_duration);

        printf("Enter cost per unit (per hour/day)");
         scanf("%f", &rentals[i].cost_per_unit);

        rentals[i].total_cost = rentals[i].rental_duration * rentals[i].cost_per_unit;
       }
     printf("\nDo you want to add more rentals? Enter number 0 for none");
      scanf("%d",&add_more);

    if (add_more>0) {
        rentals=(Rental *)realloc(rentals,(count+add_more) * sizeof(Rental));
        if (rentals == NULL) {
          printf("Memory reallocation failed!\n");
               return 1;
         }

        for (i = count; i < count + add_more; i++) {
            printf("\n--- Rental %d ---\n",i+1);
            printf("Enter rental duration (hours/days): ");
            scanf("%d", &rentals[i].rental_duration);

            printf("Enter cost per unit (per hour/day): ");
            scanf("%f",&rentals[i].cost_per_unit);
            rentals[i].total_cost=rentals[i].rental_duration * rentals[i].cost_per_unit;
           }
          count+=add_more;
        }

    int total_time=0;
     int highest=rentals[0].rental_duration;
     for (i=0;i<count;i++) {
         total_time+=rentals[i].rental_duration;

         if (rentals[i].rental_duration>highest)
             highest=rentals[i].rental_duration;
         }

    FILE *fp=fopen("Rental_Invoices.txt", "w");
    if (fp==NULL) {
        printf("Error opening file!\n");
         free(rentals);
         return 1;
     }

    fprintf(fp, "-------- Car Rental Invoices --------\n\n");

    for (i = 0; i<count; i++) {
        fprintf(fp, "Customer %d:\n", i + 1);
        fprintf(fp, "Rental Duration: %d (hours/days)\n", rentals[i].rental_duration);
        fprintf(fp, "Cost per Unit: %.2f\n", rentals[i].cost_per_unit);
        fprintf(fp, "Total Cost: %.2f\n\n", rentals[i].total_cost);
    }

    fprintf(fp, "---------------------------------------\n");
    fprintf(fp, "Total Rental Time for the Day: %d\n",total_time);
    fprintf(fp, "Highest Rental Duration: %d\n",highest);

    fclose(fp);
    
    printf("\nInvoices saved to Rental_Invoices.txt successfully.\n");
    free(rentals);
    return 0;
}

