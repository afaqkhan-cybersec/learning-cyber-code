
#include <stdio.h>

void total_value (float *price, int *stock, float *total);
void discounted_value (float *total, int *stock);

int main () {

    int i, j;
    float price[5];
    int stock[5];
    float total[5];

    for (i=0; i<5; i++) {
        printf ("Enter price of book %d:", i+1);
        scanf ("%f", &price[i]);
    }

    for (j=0; j<5; j++) {
        printf ("Enter stock value for book %d:", j+1);
        scanf ("%d", &stock[j]);
    }

    total_value (price, stock, total);

    discounted_value (total, stock);
    for (i=0; i<5; i++) {
        printf ("Total value for book %d = %.2f\n",i+1, total[i]);
    }

    return 0;
}

void total_value (float *price, int *stock, float *total) {
int i;
    for (i=0; i<5; i++) {
        total[i] = price[i] * stock[i];
    }
}

void discounted_value (float *total, int *stock) {
int i;
    for (i=0; i<5; i++) {
        if (stock[i] < 3) {
            total[i] = total[i];
        } else if (stock[i] >= 3 && stock[i]<=5) {
            total[i] = total[i] - (total[i] * 0.1);
        } else if (stock[i] >5) {
            total[i] = total[i] - (total[i] * 0.2);
        }
    }
}


