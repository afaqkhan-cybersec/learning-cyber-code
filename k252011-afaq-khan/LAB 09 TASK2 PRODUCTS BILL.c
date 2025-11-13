#include <stdio.h>
void calcTotal(float *price,float *total_bill) ;
  int main() {
    float price[5], total = 0;
      int i;

    printf("Please enter your product prices:\n");
     for(i = 0; i < 5; i++) {
    printf("Price of product %d: ", i + 1);
    scanf("%f", &price[i]);
    }

    calcTotal(price, &total);
    printf("Total bill after discounts: Rs. %.2f\n", total);
    return 0;
}
void calcTotal(float *price, float *total_bill) {
    float discount, discounted_price;
    int i;

    for(i=0;i <5; i++) {
      if (*(price + i) < 1000){
            discount = 0.10;
        }
     else if (1000<*(price + i)&&*(price + i) <= 5000){
            discount = 0.15;}
        else if (*(price + i)>5000){
            discount = 0.25;
			}

       discounted_price =*(price + i)-(*(price + i)*discount);
       *total_bill +=discounted_price;
    }
    }

