#include <stdio.h>
#include <string.h>

   float calculate_sections_score(int *attempted,int *correct,int total_questions,float marks_per_question,float negative_marks);
   
   float calculate_weighted_testscore(float english_score,float iq_score,float basic_maths_score,float advance_maths_score);
   
   float calculate_aggregate(float *test_score,float *inter_marks,float *matric_marks);
   
   void departments_allocation(float *aggregate);
   

 int main() {
 	printf("=========================================================\n");
    printf("|WELCOME TO FAST UNIVERSITY KARACHI ADMISSION CALCULATOR|\n");
    printf("=========================================================\n\n");
 
    char name[50];
    char arn[21];
    float matric_marks,inter_marks;
    int attempted_english,correct_english,attempted_iq,correct_iq;
    int attempted_basic_maths,correct_basic_maths,attempted_advance_maths,correct_advance_maths;

  
  
    do {
        printf("Enter your ARN number\n");
        scanf("%20s",arn);
        if (strlen(arn) >20)
		 {
            printf("invalid ARN enter upto 20 characters\n");
        } 
		else break;
      } 
	while (1);
	

    getchar(); 
    printf("Enter your Name\n");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name, "\n")]= 0;
    
 
    do {
        printf("Enter matric  marks percentage\n");
        scanf("%f", &matric_marks);
        if (matric_marks<0||matric_marks>100)
		{	
        printf("Invalid marks please enter between 0 and 100\n");
		}
        else break;
      } 
	while (1);
	

    do {
        printf("Enter intermediate marks percentage)\n");
        scanf("%f", &inter_marks);
        if (inter_marks<0||inter_marks>100)
		{
        printf("Invalid marks please enter between 0 and 100\n");
		}
        else break;
      } 
	while (1);


    do {
        printf("\n***English section(30 mcqs)***\n");
        printf("enter attempted\n"); 
		scanf("%d",&attempted_english);
        printf("enter correct\n"); 
		scanf("%d",&correct_english);
        if ( attempted_english<0||correct_english<0 ||correct_english>attempted_english||attempted_english>30)
            printf("Invalid input please try again\n");
        else break;
      } 
	while (1);
    

    do {
        printf("\n***IQ section(20 mcqs)***\n");
        printf("Attempted\n");
		scanf("%d",&attempted_iq);
        printf("Correct\n"); 
		scanf("%d",&correct_iq);
        if (attempted_iq<0||correct_iq<0||correct_iq>attempted_iq||attempted_iq>20)
		{
            printf("Invalid entry try again\n");
			}
        else break;
      } 
	while (1);
    

    do {
        printf("\n***Basic maths section(20 msqs)***\n");
        printf("Attempted\n"); 
		scanf("%d",&attempted_basic_maths);
        printf("Correct\n"); 
		scanf("%d",&correct_basic_maths);
        if (attempted_basic_maths<0||correct_basic_maths<0||correct_basic_maths>attempted_basic_maths||attempted_basic_maths>20)
            {
			printf("Invalid input please try again\n");
		}
        else break;
      } 
	while (1);
    

    do {
        printf("\n***Advanced maths section(50mcqs)***\n");
        printf("Attempted\n"); 
		scanf("%d",&attempted_advance_maths);
        printf("Correct\n"); 
		scanf("%d", &correct_advance_maths);
        if (attempted_advance_maths<0||correct_advance_maths<0||correct_advance_maths>attempted_advance_maths||attempted_advance_maths>50)
            {
			printf("Invalid input try again\n");
		}
        else break;
      } 
	while (1);


    float english_score=calculate_sections_score(&attempted_english,&correct_english,30,0.33,0.0833);
    
    float iq_score=calculate_sections_score(&attempted_iq,&correct_iq,20,1.0,0.25);
    
    float basic_maths_score=calculate_sections_score(&attempted_basic_maths,&correct_basic_maths,20,1.0,0.25);
    
    float advance_maths_score=calculate_sections_score(&attempted_advance_maths,&correct_advance_maths,50,1.0,0.25);

    float total_test_score=calculate_weighted_testscore(english_score,iq_score,basic_maths_score,advance_maths_score);
    
    float aggregate=calculate_aggregate(&total_test_score,&inter_marks,&matric_marks);


    printf("\n\n******Results******\n");
    printf("Student: %s (ARN: %s)\n",name,arn);
    printf("Matric marks: %.2f%%\n",matric_marks);
    printf("Intermediate marks: %.2f%%\n",inter_marks);
    printf("Weighted Test Score out of 100 is: %.2f\n",total_test_score*2);
    printf("Final aggregate (%%): %.2f\n",aggregate);

    departments_allocation(&aggregate);

    return 0;
   }




 float calculate_sections_score(int *attempted,int *correct,int total_questions,float marks_per_question,float negative_marks)
 {
    int wrong=*attempted- *correct;
    if (wrong<0) 
	wrong=0;
    float score=(*correct * marks_per_question)-(wrong * negative_marks);
    if (score<0) 
	score=0;
    return score;
      }
      

   float calculate_weighted_testscore(float english_score,float iq_score,float basic_maths_score,float advance_maths_score) 
   {
      float english_max_marks=30 * 0.33;
      float iq_max_marks=20 * 1.0;
      float basic_max_marks=20 * 1.0;
      float advance_maths_max_marks=50 * 1.0;
      float total_max_marks=english_max_marks+iq_max_marks+basic_max_marks + advance_maths_max_marks;

      float total_score=english_score+iq_score+basic_maths_score+advance_maths_score;
      return (total_score/total_max_marks) * 50.0;
      }



    float calculate_aggregate(float *total_test_score,float *inter_marks,float *matric_marks) 
    {
    return (*total_test_score)+(*inter_marks*0.4)+(*matric_marks*0.1);
      }



    void departments_allocation(float *aggregate) 
       {
      printf("\nEligible Departments (FAST Karachi - CS-related):\n");
    
    if (*aggregate>=67.0)
	 {
        printf("BS Computer science\n");
        
        printf("BS Software engineering\n");
        
        printf("BS Artificial intelligence\n");
        
        printf("BS Cybersecurity\n");
        
        printf("BS Data science\n");  
    } 
    
	else if (*aggregate>=65.0 && *aggregate<67.0) 
	{
        printf("BS Artificial intelligence\n");
        
        printf("BS Software engineering\n");
        
        printf("BS Cybersecurity\n");
        
        printf("BS Data science\n");
    } 
    
	else if (*aggregate>=63.0 && *aggregate<65.0) {
		
       printf("BS Software engineering\n");
        
       printf("BS Cybersecurity\n");
        
       printf("BS Data science\n");
    } 
    
	else {
        printf("No CS-related departments available based on  the current merit cutoff.\n");
    }
 }

