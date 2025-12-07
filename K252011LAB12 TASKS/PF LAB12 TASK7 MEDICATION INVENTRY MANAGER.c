#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct {
    char name[50];
    int quantity;
    float price;
 } medicine;

 void save_to_file(medicine *list,int count) {
    FILE *fp=fopen("medicine_inventory.txt", "w");
    if (fp==NULL) {
        printf("File creation error!\n");
          return;
      }

    fprintf(fp, "Medicine Inventory Report\n\n");
    int i;
    for (i = 0; i < count; i++) {
        fprintf(fp, "Medicine %d:\n",i+1);
        fprintf(fp, "Name: %s\n", list[i].name);
        fprintf(fp, "Quantity: %d\n",list[i].quantity);
        fprintf(fp, "Unit Price: %.2f\n\n",list[i].price);
    }

    fclose(fp);
}

int main() {
    int count, choice;

    printf("Enter number of medicines initially");
      scanf("%d",&count);

    medicine *list = (medicine *)malloc(count * sizeof(medicine));
      if (list==NULL) {
        printf("Memory allocation failed!\n");
            return 1;
       }
    int i;
    for (i= 0;i< count;i++) {
        printf("\n--- Medicine %d ---\n",i + 1);
        printf("Enter name: ");
        scanf(" %[^\n]",list[i].name);
        printf("Enter quantity: ");
        scanf("%d",&list[i].quantity);
        printf("Enter unit price: ");
        scanf("%f",&list[i].price);
    }

    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Show Low Stock (quantity<5)\n");
        printf("4. Show Total Inventory Value\n");
        printf("5. Save & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice==1) {
            count++;
            list = (medicine *)realloc(list, count * sizeof(medicine));

            if (list == NULL) {
                printf("Reallocation failed!\n");
                  return 1;
            }

            printf("\n--- Add New Medicine ---\n");
            printf("Enter name: ");
            scanf(" %[^\n]", list[count - 1].name);
            printf("Enter quantity: ");
            scanf("%d", &list[count - 1].quantity);
            printf("Enter unit price: ");
            scanf("%f", &list[count-1].price);

            printf("Medicine added successfully.\n");
        }

         else if (choice==2) {

            if (count==0) {
                 printf("No medicines to remove.\n");
                  continue;
            }

            int remove_index;
             printf("Enter medicine number to remove (1 to %d)",count);
              scanf("%d",&remove_index);

            if (remove_index<1||remove_index>count) {
                 printf("Invalid index!\n");
                   continue;
              }
              int i;
              for (i=remove_index-1;i<count-1;i++) {
                 list[i]=list[i+1];
              }

              count--;
            list=(medicine *)realloc(list, count * sizeof(medicine));

            printf("Medicine removed successfully.\n");
        }

          else if (choice==3) {

             printf("\n--- LOW STOCK ALERTS ---\n");
              int found=0;
              int i;
              for (i=0; i<count;i++) {
                  if (list[i].quantity<5) {
                     printf("Medicine: %s — Qty: %d\n", list[i].name, list[i].quantity);
                       found=1;
                }
            }
           if (!found)
                 printf("No low-stock medicines.\n");
          }

        else if (choice==4) {
            float total_value = 0;
            int i;
              for (i=0; i<count;i++) {
                total_value += list[i].quantity * list[i].price;
            }
            printf("\nTotal Inventory Value = Rs %.2f\n", total_value);
        }

        else if (choice == 5) {
            save_to_file(list, count);
             printf("\nInventory saved to medicine_inventory.txt.\n");
               break;
        }

         else {
            printf("Invalid choice! Try again.\n");
         }
       }

    free(list);
        return 0;
}

