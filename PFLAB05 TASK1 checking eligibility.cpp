#include <stdio.h>
int main()
{
	
	int age;
	float account_balance;
	printf("enter your age:\n");
	scanf("%d", &age);
	printf("enter your account balance:\n");
	scanf("%f", &account_balance);
	if (age<21){
		printf("Not eligible for ride (underage)");
	}
	else if(account_balance<200){
	  
		printf("Not eligible (insufficient balance)");
	}
	else
	
	printf("Eligible for ride");
			
	return 0;
}
