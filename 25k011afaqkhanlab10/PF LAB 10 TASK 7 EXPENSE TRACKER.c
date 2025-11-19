#include <stdio.h>

int main() {
    FILE *fp;
    char category[50];
    float amount;
    
    printf("Enter expense category\n");
      scanf("%s",category);

    printf("Enter amount");
     scanf("%f",&amount);

    fp=fopen("expenses.txt","a");

    if (fp==NULL) {
        printf("Error opening expenses.txt\n");
          return 1;
    }

    fprintf(fp,"%s %.2f\n",category,amount);
      fclose(fp);

    printf("\nExpense saved successfully!\n");

       fp=fopen("expenses.txt","r");
    
       if (fp==NULL) {
        printf("Could not read expenses.txt\n");
        return 1;
    }
    printf("\n----- All Expenses -----\n");

     while (fscanf(fp,"%s %f",category,&amount)!= EOF) {
        printf("Category: %s, Amount: %.2f\n",category,amount);
    }
      fclose(fp);

    return 0;
}

