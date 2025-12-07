#include<stdio.h>
int maxtip(int tips[], int n, int i){
	
	if(i>=n){
		return 0;
	}
	if (i==n-1){
		return tips[i];	
	}
	int take=tips[i]+maxtip(tips,n,i+1);
	int skip;
	if(i+2<=n){
		skip=maxtip(tips,n,i+2);
	}else{
		skip=0;
	}
	if(take>skip){
		return take;
	}else{
		return skip;
	}
}
int i;
int main(){
	int n; 
	
	printf("Enter num of delivery stops: ");
	scanf("%d",&n);
	
	int tips[n];
	printf("\nEnter tip amounts for %d stops: ",n);
	for(i=0;i<n;i++){
		printf("\nTip for stop %d: \n",i+1);
		scanf("%d", &tips[i]);
		
	}
	int result=maxtip(tips,n,0);
	printf("\nMaximum total tip collection is: %d",result);

	return 0;
	
}

