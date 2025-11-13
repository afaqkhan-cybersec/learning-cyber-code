#include<stdio.h>
int main(){
	int section_strength[6];
	int invigilators[6];
	int chief_invigilator=0;
	int total_invigilators=0;
	int total_strength;
	int i;
	for(i=0;i<6;i++){
	printf("enter number of students for section: %d\n",i+1);	
	scanf("%d",&section_strength[6]);
	if(section_strength[6]<30){
		invigilators[i]=0;
	}
	else if (section_strength[6]==30){
		invigilators[i]=1;
	  }
	else if(section_strength[6]>=31&&section_strength[6]<=60){
		invigilators[i]=2;
	  }
	else{
	    invigilators[i]=3;
	  }
	total_invigilators=total_invigilators+invigilators[i];
	total_strength=total_strength+section_strength[6];
  }
	if (total_strength>300){
		chief_invigilator=1;
	  }
	int final_invigilators=chief_invigilator+total_invigilators;
	printf("\n=============================================\n");
	printf("\t====Summary Chart====\n");
	printf("=============================================\n");
	printf("\tSection\tInvigilators\n");
	for(i=0;i<6;i++){
		printf("\t%d",i+1);
		printf("\t\t%d\n",invigilators[i]);
	}
	printf("Total invigilators needed are: %d\n",final_invigilators);
	return 0;
}
