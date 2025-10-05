#include<stdio.h>
main(){
	int members;
	int water_usage;
	
	printf("Enter total family members");
	scanf("%d", &members);
	printf("Enter monthly usage of water in liters");
	scanf("%d", &water_usage);

	if(water_usage<3000){
		printf("no fine");			
	}
	else {
	
	
	
	if(members>6){
			printf("Allowed Large Family Exception");
		}
	else{
		printf("Fine applied");
	}
}
	return 0;
}
