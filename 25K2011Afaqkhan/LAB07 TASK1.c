#include<stdio.h>
int main(){
 float price[10],discounted_price=0,total=0;
 int i;

 for (i=0; i<10; i++){
  printf("Enter your product:%d price\n", i+1);
  scanf(" %f",&price[i]);
 if(price[i]<1000){
 	discounted_price=price[i]-(price[i]*.05);
   }
 else if(1000<=price[i]&&price[i]<=5000){
 	discounted_price=price[i]-(price[i]*.10);	
	 }
 else{
 	discounted_price=price[i]-(price[i]*.15);	
	 }	
	total=total+discounted_price;
	printf("PRICE of product %d: is %.2f\n",i+1,discounted_price);
}
	printf("=========BILL REPORT==========\n");
	printf("total purchase is %.2f\n",total);
	if (total>25000){
	printf("you got a gold voucher\n");
	}
	else{
		printf("No voucher awarded");
	}	
	return 0;
}
