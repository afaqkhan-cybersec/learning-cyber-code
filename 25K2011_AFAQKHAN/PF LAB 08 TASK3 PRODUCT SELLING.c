#include <stdio.h>

int main() {
    int sales[4][5];
    int totalSalesman[4] = {0};
    int totalProduct[5] = {0};
    int i, j;
    
    for (i = 0; i < 4; i++) {
        printf("\nEnter sales for Salesman %d:\n", i + 1);
        for (j = 0; j < 5; j++) {
            printf("  Product %d: ", j + 1);
            scanf("%d", &sales[i][j]);
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            totalSalesman[i]= totalSalesman[i]+ sales[i][j];
        }
    }
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 4; i++) {
            totalProduct[j]=totalProduct[j] + sales[i][j];
        }
    }
    int maxProduct = totalProduct[0];
    int maxProductIndex = 0;
    for (j = 1; j < 5; j++) {
        if (totalProduct[j] > maxProduct) {
            maxProduct = totalProduct[j];
            maxProductIndex = j;
        }
    }
   int bestSalesmanindex = 0;
    int maxSale = sales[0][maxProductIndex];
    for (i = 1; i < 4; i++) {
        if (sales[i][maxProductIndex] > maxSale) {
            maxSale = sales[i][maxProductIndex];
            bestSalesmanindex = i;
        }
    }

    for (i = 0; i < 4; i++) {
        if (totalSalesman[i] > 10000) {
            totalSalesman[i] += totalSalesman[i] * 0.10;
        }
    }
    printf("\n--------------------------------------------\n");
    printf("Total sales per salesman:\n");
    for (i = 0; i < 4; i++) {
        printf("  salesman %d: made sell of Rs: %d\n", i + 1, totalSalesman[i]);
    }

    printf("\nTotal sales per product:\n");
    for (j = 0; j < 5; j++) {
        printf("  Product %d: made sell of Rs: %d\n", j + 1, totalProduct[j]);
    }
    printf("Most expensive product is product %d (Rs. %d total)\n",
           maxProductIndex + 1, maxProduct);
    printf("Salesman who sold it on the highest price is salesman %d (who sold it for Rs. %d)\n",
           bestSalesmanindex + 1, maxSale);

    return 0;
}
