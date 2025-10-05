#include<stdio.h>
main(){
	int usage;
	printf("Enter daily water usage in liters  ");
	scanf("%d", &usage);
	
	if(usage<=100) {
		printf("Efficient Usage");
}
	else{
		printf("High Usage Detected");
	}
	return 0;
}
