#include<stdio.h>
int main(){
int patients[7];
int total=0;
int i;
for (i=0;i<7;i++){
	printf("Enter number of patients for ward: %d\n",i+1);
	scanf("%d", &patients[i]);}
	for (i=0;i<7;i++){

	if (patients[i]>10){
		printf( "ward: %d is overcrowded\n",i+1);
		printf( "ward: %d needs administrative review(overcrowded)\n",i+1);
	}
	else if(patients[i]>=6&&patients[i]<=10){
		printf( "ward: %d is stable\n",i+1);
	}
	else {
		printf( "ward: %d is underutilized\n",i+1);
		printf( "ward: %d needs administrative review(underutilized)\n",i+1);
	}
	total=total+patients[i];
}
	printf("Total number of patients admitted are: %d \n",total );
	return 0;
}
