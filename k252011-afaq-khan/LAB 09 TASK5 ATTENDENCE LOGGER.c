#include <stdio.h>
void checkattendance(int (*attendance)[5]);
int main(){
	int attendance[3][5];
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<5;j++){
			printf("Enter attendence(1 for present and 0 for absent) of student %d for day %d\n",i+1,j+1);
			scanf("%d",&attendance[i][j]);
			if(attendance[i][j]!=0&&attendance[i][j]!=1){
				printf("invalid entery\n");
				j--;
			}
		}
	}
	checkattendance(attendance);
	
	return 0;
}
void checkattendance(int (*attendance)[5]){
int count, i,j,defaulter=0;
float student[3];
	for(i=0;i<3;i++){	
	  count=0;
		for(j=0;j<5;j++){
			if(attendance[i][j]==1){
	           count++;
       }
	}	
	student[i]=(count/5.0)*100;
			printf("Student %d attendance=%.2f%%\n",i+1,student[i]);
				if(student[i]>=90&&student[i]<=100){
					printf("good attendance\n");
				}
				else if(student[i]>=75&&student[i]<=89){
					printf("average attendance\n");
					
				}
				else if(student[i]>=0&&student[i]<=74){
					printf("poor attendance\n");
						defaulter++;
				}
			
 }
 printf("Total number of defaulters are %d",defaulter);
}
