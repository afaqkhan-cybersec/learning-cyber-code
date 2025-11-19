#include <stdio.h>

  int main() {
    char name[50];
    float price;
    int quantity;

    FILE *file;
    file=fopen("products.txt","a");
    if (file==NULL){
        printf("Error file not opening\n");
            return 1;
    }
    printf("Enter product name\n");
       scanf("%s",name);

    printf("Enter product price\n");
       scanf("%f",&price);

    printf("Enter product quantity\n");
     scanf("%d",&quantity);

    fprintf(file,"Name: %s, Price= %.2f, Quantity= %d\n",name,price,quantity);

        fclose(file);
    
    printf("Product data saved successfully!\n");

    return 0;
}

