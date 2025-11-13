#include <stdio.h>

void callaverage(float (*mileage)[7], float *average, char *category, int day);
void display_compact(float *average, char *category, int vehicles);
void display_detailed(float *average, char *category, int vehicles);

int main() {
    int day =7,vehicles = 5;
    float mileage[5][7];
    float average[5];
    char category[5];
    int i, j;

    for (i = 0; i < vehicles; i++) {
        for (j = 0; j < day; j++) {
            printf("Enter mileage for vehicle %d for day %d: ", i + 1, j + 1);
            scanf("%f",&mileage[i][j]);
        }
    }
    callaverage(mileage,average,category,day);

    void (*display_func)(float *,char *,int);
    int choice;

    printf("Select display format 1 for Compact 2 for Detailed\n");
    scanf("%d",&choice);

    if (choice==1)
        display_func=display_compact;
    else
        display_func=display_detailed;

    display_func(average,category,vehicles);

    return 0;
}

void callaverage(float (*mileage)[7],float *average, char *category, int day) {
    int i, j;
    float sub_total;

    for (i=0; i<5;i++) {
       sub_total = 0;
    for (j=0;j<7;j++) {
     sub_total+=mileage[i][j];
        }
        average[i]=sub_total/day;
    if (average[i] >= 18)
           category[i]='E';
       else if (average[i]>= 12)
           category[i]='M';
       else
            category[i]='P';
     }
  }

void display_compact(float *average,char *category,int vehicles) {
	int i;
    printf("Compact report\n");
    printf("Vehicle\tCategory\n");
    for (i = 0; i < vehicles; i++) {
        printf("%d\t%c\n", i + 1, category[i]);
     }
 }

void display_detailed(float *average,char *category,int vehicles) {
	int i;
    printf("Detailed Report\n");
    printf("Vehicle\tAverage Mileage\tCategory\n");
    for (i = 0; i < vehicles; i++) {
     char *full_category;
       if (category[i] =='E') full_category ="Efficient";
        else if (category[i]=='M') full_category="Moderate";
      else full_category="Poor";

        printf("%d\t%.2f\t\t%s\n", i+ 1, average[i], full_category);
 }
}

