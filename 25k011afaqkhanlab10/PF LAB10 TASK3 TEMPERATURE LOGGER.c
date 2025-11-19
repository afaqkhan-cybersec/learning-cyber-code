#include <stdio.h>

int main() {

    FILE *fp;
    char city[50];
    float temp;
    char maxCity[50];
    float maxTemp=-100;
    int i;

    fp=fopen("temperature.txt","w");
    if (fp==NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("Enter names and temperatures of 5 cities:\n");

    for (i =0;i <5 ;i++) {
        printf("\nCity %d name:",i+1);
        scanf("%s",city);

        printf("Average temperature:");
        scanf("%f",&temp);

        fprintf(fp,"%s %.2f\n",city,temp);
    }

    fclose(fp);

    fp = fopen("temperature.txt","r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    while (fscanf(fp,"%s %f", city, &temp) != EOF) {
        if (temp>maxTemp) {
            maxTemp=temp;
            strcpy(maxCity,city);
        }
     }

    fclose(fp);

    printf("\nCity with highest temperature:\n");
    printf("%s with %.2f°C\n",maxCity,maxTemp);

    return 0;
    }

