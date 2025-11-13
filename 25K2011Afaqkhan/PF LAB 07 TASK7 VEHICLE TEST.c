#include<stdio.h>
int main(){
	int mileage_value[8];
	int i;
	int count=0;
	for(i=0;i<8;i++){
	printf("Enter mileage value for Vehicle: %d\n",i+1);
	scanf("%d",&mileage_value[i]);
	}
	printf("\n=============================================\n");
	printf("\t====Test Summary====\n");
	printf("=============================================\n");
	for(i=0;i<8;i++){
	if (mileage_value[i]>=18){
		printf( "Vehicle: %d is under Efficiency category\n",i+1);
	}
	else if(mileage_value[i]>=12&&mileage_value[i]<=17){
		printf( "Vehicle: %d is under Average category\n",i+1);
	}
	else {
		printf( "Vehicle: %d is under Needs maintenance category\n",i+1);
		count++;
		}
	}
	if(count>3){
			printf( "Fleet Efficiency Alert!\n",i+1);
	}
	return 0;
}
	
