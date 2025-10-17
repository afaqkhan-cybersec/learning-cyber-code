#include <stdio.h>
int main(){
	int points;
	printf("please enter your loyalty points\n");
	scanf(" %d",&points);
	
	float discount=(points>1000)?20:5;
	
	printf("persentage is %.2f%%\n",discount);
	return 0;
}
