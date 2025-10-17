#include <stdio.h>
int main()
{
	int driver_rating;
	float driver_distance;
	printf("enter driver rating(1..5):\n");
	scanf("%d", &driver_rating);
	printf("enter passenger distance from driver:\n");
	scanf("%f", &driver_distance);
	if (driver_rating>=4&&driver_distance<=5){
		printf("Top driver nearby\n");
	}
	else if(driver_rating>=3&&driver_distance<=10){
	  
		printf("Average driver assigned\n");
	}
	else
	
	printf("No suitable driver available");
			
	return 0;
}

