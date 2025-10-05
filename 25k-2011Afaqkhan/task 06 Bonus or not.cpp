#include<stdio.h>
main(){
	int water_usage;
	int days;
	
	printf("Enter monthly usage of water in liters: ");
	scanf("%d", &water_usage);
	printf("Enter number of days water was saved: ");
	scanf("%d", &days);
	
	if(water_usage<2500 && days>10){
		printf("Bonus: 300 PKR Discount");
	}else{
		printf("No Bonus");
	}
	
	return 0;
}
