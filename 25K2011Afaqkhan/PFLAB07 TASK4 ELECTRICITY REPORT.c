#include<stdio.h>
int main(){
	int units[7];
	int bill[7];
	int total_revenue=0;
	int flaged_houses=0;
	int count=0;
	int i;
	for(i=0;i<7;i++){
		printf("enter units for House: %d \n",i+1);
		scanf("%d",&units[i]);
		if (units[i]<=200){
			bill[i]=15*units[i];
		}
		else if(units[i]>=201&&units[i]<=500){
			bill[i]=20*units[i];
		}
		else{
		    bill[i]=25*units[i];
		    if(units[i]>700){
		    	count++;
			}
	}
	total_revenue=total_revenue+bill[i];
	}
	printf("\n\t=============================================\n");
	printf("\t====summary of the electricity bill====\n");
	printf("\t=============================================\n");
	for(i=0;i<7;i++){
		
	printf("\tTotal bill for house: %d is =%d \n",i+1,bill[i]);

}
	printf("\tTotal number of flaged houses are: %d\n",count);
	printf ("\tTotal revenue is: %d\n", total_revenue);
	return 0;
}
