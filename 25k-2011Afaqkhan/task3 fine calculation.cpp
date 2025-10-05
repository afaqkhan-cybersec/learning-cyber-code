#include<stdio.h>
main(){

	int water_usage;
	printf("Enter your monthly water usage in liters: ");
	scanf("%d", &water_usage);
	
	if(water_usage<=3000){
	
	
		printf("Bill = 500 PKR \n");
		printf("No Fine/n");
	}else if(water_usage>=3001&&water_usage<=5000){
	
		printf("Bill = 1000 PKR\n");
		printf("Fine = 200 PKR\n");
		printf("Total Bill= 1200 PKR");
	} else if(water_usage>=5001&& water_usage<=7000){
	
	    printf("Bill = 1000 PKR\n");
	    printf("Fine = 500 PKR\n");
	    printf("Total Bill= 1500 PKR");
	}else{
	
		printf("BILL = 1000\n");
		printf("Fine = 1000 + wATER SUPPLY RESTRICTED\n");
		printf("Total Bill= 2000 PKR");
}
	return 0;
}

