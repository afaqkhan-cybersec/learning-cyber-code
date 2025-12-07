#include <stdio.h>

  struct Customer {
      char name[50];
      int meterID;
      int units;
      float finalBill;
    };

 float calculateBillRecursive(int units) {
    if (units<=0)
        return 0;

    if (units<=100) {
        return units * 0.05 +calculateBillRecursive(0);
    }

    if (units<=300) {
        return 100* 0.05+(units-100)*0.12+calculateBillRecursive(0);
    }

      return 100*0.05+200*0.12 +(units- 300)*0.18+ calculateBillRecursive(0);
   }

 int main() {
     struct Customer c;

     printf("Enter Customer Name\n");
     fgets(c.name, sizeof(c.name), stdin);

    printf("Enter Meter ID\n");
     scanf("%d", &c.meterID);

    printf("Enter Consumed Units\n");
       scanf("%d",&c.units);

    c.finalBill=calculateBillRecursive(c.units);

    printf("\n----- Final Bill -----\n");
    printf("Name: %s",c.name);
    printf("Meter ID: %d\n",c.meterID);
    printf("Units Consumed: %d\n",c.units);
    printf("Total Bill (Tax Only): %.2f\n",c.finalBill);

    return 0;
    
    }

