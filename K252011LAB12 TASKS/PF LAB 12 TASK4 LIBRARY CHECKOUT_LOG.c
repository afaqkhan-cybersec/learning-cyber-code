#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct {
    char book_title[100];
    char member_id[20];
    int checkout_time;
    int return_due_days;
 } checkout_log;

  int main(){
     int count,add_more,i;
     
    printf("Enter number of book checkouts initially: ");
      scanf("%d",&count);
    
      checkout_log *logs= (checkout_log *)malloc(count * sizeof(checkout_log));
    
    	if (logs==NULL) {
         printf("Memory allocation failed!\n");
           return 1;
        }

    for (i=0;i<count;i++) {
        printf("\n--- Checkout %d ---\n", i + 1);
        printf("Enter book title:");
        scanf(" %[^\n]",logs[i].book_title);
        printf("Enter member ID:");
        scanf("%s",logs[i].member_id);
        printf("Enter checkout hour (0-23):");
        scanf("%d",&logs[i].checkout_time);
        printf("Enter return due days:");
        scanf("%d",&logs[i].return_due_days);
      }

    printf("\nDo you want to add more checkouts? Enter number 0 for none");
        scanf("%d",&add_more);

     if (add_more>0) {
        logs=(checkout_log *)realloc(logs,(count+add_more) * sizeof(checkout_log));
          if (logs==NULL) {
            printf("Memory reallocation failed!\n");
               return 1;
           }
        for (i=count;i<count+add_more;i++) {
            printf("\n--- Checkout %d ---\n", i + 1);
            printf("Enter book title: ");
            scanf(" %[^\n]", logs[i].book_title);
            printf("Enter member ID: ");
            scanf("%s", logs[i].member_id);
            printf("Enter checkout hour (0-23): ");
            scanf("%d", &logs[i].checkout_time);
            printf("Enter return due days: ");
            scanf("%d",&logs[i].return_due_days);
          }
          count+=add_more;
        }

    FILE *fp=fopen("checkout_logs.csv", "w");
    if (fp == NULL) {
        printf("File creation error!\n");
        free(logs);
        return 1;
    }

    fprintf(fp, "Book Title,Member ID,Checkout Hour,Return Due Date\n");
    for (i=0;i< count;i++) {
        fprintf(fp, "%s,%s,%d,%d\n",
                logs[i].book_title,
                logs[i].member_id,
                logs[i].checkout_time,
                logs[i].return_due_days);
    }

    fclose(fp);
       printf("\nCheckout logs saved to checkout_logs.csv successfully.\n");

    free(logs);
       return 0;
   }

