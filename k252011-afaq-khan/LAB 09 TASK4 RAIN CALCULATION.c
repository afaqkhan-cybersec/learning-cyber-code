#include <stdio.h>  

void calcRain(float *rain, float *average, float *max, int *max_index, int *rainy, int size);  

int main () {  
    float rain[7] = {0};   
    float average = 0;  
    float max = 0; 
	int max_index=0; 
    int rainy = 0;   
    int i;  

    printf("Enter rain data:\n");  
    for (i = 0; i < 7; i++) {  
        scanf("%f", &rain[i]);  
    }  

    calcRain(rain, &average, &max,&max_index, &rainy, 7);   

    printf("\nAverage rainfall is %.2f\n", average);  
    printf("Maximum rainfall is on day:%d which is %.2f\n", max_index,max);  

    if (rainy == 1) {  
        printf("It's a rainy week\n");  
    } else {  
        printf("It's a sunny week\n");  
    }  

    return 0;  
}  

void calcRain(float *rain, float *average, float *max,int *max_index, int *rainy, int size) {  
    int i; 
	int greater=0; 
    float total = 0;  
    int correct = 0;   
    for (i = 0; i < size; i++) {  
        total = *(rain+i) + total;  
    }  
    *average = total / size;  
    *max = *(rain+0); 
	*max_index=1; 
    for (i = 0; i < size; i++) {  
        if (*(rain+i) > *max) {   
            *max = *(rain+i);
			*max_index=1+i ; 
        }  
    }  
    for (i = 0; i < size; i++) {  
        printf("Rain data for day %d is %.2f\n", i + 1, *(rain+i));  
          
        if (*(rain+i) > *average) {   
            greater++;  
        }  
    }  
    if (greater>= 3) {  
        *rainy = 1;  
    }  
}  

