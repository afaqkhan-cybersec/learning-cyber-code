#include <stdio.h>
#include <string.h>

  struct Category {
    char categoryName[50];
    char department[50];
  };
  struct Product {
    char productName[50];
      int expiryDays;
       struct Category category;
  };

  void checkExpiry(struct Product products[],int index,int total,int N) {
     if (index==total)
          return;
    if (products[index].expiryDays<=N) {
        printf("ALERT: %s (Category: %s, Dept: %s) expires in %d days!\n",
                products[index].productName,
                products[index].category.categoryName,
                products[index].category.department,
                 products[index].expiryDays);
    }

    checkExpiry(products, index+1,total,N);
     }

 int main() {
     int n,Ndays;
   int i;
    printf("Enter number of products: ");
      scanf("%d",&n);

    struct Product products[n];
      for (i= 0; i<n ;i++) {
        printf("\nEnter Product %d Name: ", i + 1);
           scanf("%s",products[i].productName);

        printf("Enter Expiry Days: ");
         scanf("%d",&products[i].expiryDays);

        printf("Enter Category Name: ");
          scanf("%s",products[i].category.categoryName);

         printf("Enter Department Name: ");
          scanf("%s",products[i].category.department);
       }

    printf("\nEnter N (check products expiring within N days): ");
       scanf("%d",&Ndays);

    printf("\n---- EXPIRY ALERTS ----\n");

       checkExpiry(products,0,n,Ndays);

      return 0;
    }

