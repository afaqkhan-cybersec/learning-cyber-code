#include<stdio.h>
main(){
	float PF, AP, FE, ICT,IST;
	
	printf("enter PF marks\n");
	scanf("%f", &PF);
	printf("enter AP marks\n");
	scanf("%f", &AP);
	printf("enter FE marks\n");
	scanf("%f", &FE);
	printf("enter ICT marks\n");
	scanf("%f", &ICT);
    printf("enter IST marks\n");
    scanf("%f", &IST);
    float Total= PF+AP+FE+ICT+IST;
    float Percentage=Total/500*100;
    float CGPA=(Percentage/100)*4;
    printf("\n===========================\n");
    printf("\n    STUDENT RESULT   \n");
    printf("\n===========================\n");
    
    printf("marks: %.1f %.1f %.1f %.1f %.1f \n", PF, AP, FE, ICT,IST);
    printf("total marks: %.1f\n",Total);
    printf("percentage: %.1f\n",Percentage);
    printf("CGPA: %.1f\n",CGPA);
    return 0;
}

