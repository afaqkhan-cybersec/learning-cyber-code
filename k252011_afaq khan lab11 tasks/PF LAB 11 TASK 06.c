#include<stdio.h>
#include<string.h>
 struct person{
 	char name[100];
 	int age;
 };
 
 struct student{
 	struct person person;
 	int per_credit_hour;
 	float per_credit_fee;
 	
 };
 
float calculationfee(struct student student,int subjects,int current_sub){
	
	if(current_sub==subjects){
		return 0;
	}else{
		return (student.per_credit_fee *student. per_credit_hour) + calculationfee(student,subjects,current_sub +1);
	}
}

int main(){
	struct student student;
	int subjects;
	 printf("ENTER STUDENT NAME: ");
	 scanf("%[^\n]",student.person.name);
	 printf("ENTER STUDENT'S AGE: ");
	 scanf("%d",&student.person.age);
	 printf("Enter credit hours: ");
	 scanf("%d",&student. per_credit_hour);
	 printf("Enter per credit Fee: ");
	 scanf("%f",&student.per_credit_fee);
	 printf("Enter no of Subjects: ");
	 scanf("%d",&subjects);
	 
	 float totalFee= calculationfee(student,subjects,0);
	 
	 printf("\nStudent NAME: %s\n",student.person.name);
	 printf("\nTOTAL SEMESTER FEE for %d subjects: %.2f\n", subjects,totalFee);
	 
	 return 0;
	 
}

