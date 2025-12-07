#include <stdio.h>
#include <stdlib.h>

  int main() {
    int count, add_more, i;
    float threshold;
    float max_temp,min_temp;
     int above_count=0;

    printf("Enter number of temperature readings:");
      scanf("%d", &count);

   float *temp = (float*)malloc(count * sizeof(float));
     if (temp == NULL) {
        printf("Memory allocation failed!\n");
          return 1;
    }

    printf("\nEnter the temperature readings:\n");
      for (i=0;i<count;i++) {
        printf("Reading %d: ", i+ 1);
         scanf("%f", &temp[i]);
     }

    printf("\nDo you want to add more readings? Enter number 0 for none: ");
     scanf("%d",&add_more);

    if (add_more > 0) {
        temp=(float*)realloc(temp,(count+add_more) * sizeof(float));
        if (temp==NULL) {
            printf("Reallocation failed!\n");
              return 1;
        }

        printf("\nEnter the additional readings:\n");
          for (i=count;i<count+add_more;i++) {
            printf("Reading %d: ", i+1);
               scanf("%f", &temp[i]);
        }

        count+= add_more;
     }

    printf("\nEnter alert threshold temperature: ");
      scanf("%f", &threshold);

    max_temp= temp[0];
    min_temp= temp[0];
     above_count= 0;

    for (i=0;i<count;i++) {
        if (temp[i]>max_temp)
             max_temp=temp[i];

        if (temp[i]<min_temp)
              min_temp =temp[i];

         if (temp[i]>threshold)
              above_count++;
     }

    FILE *fp = fopen("temperature_summary.txt", "w");
     if (fp == NULL) {
          printf("File write error!\n");
        free(temp);
           return 1;
      }

    fprintf(fp, "Temperature Monitoring Summary Report\n");
    fprintf(fp, "-----------------------------------\n");
    fprintf(fp, "Total Readings: %d\n",count);
    fprintf(fp, "Highest Temperature: %.2f\n",max_temp);
    fprintf(fp, "Lowest Temperature: %.2f\n",min_temp);
    fprintf(fp, "Threshold: %.2f\n",threshold);
    fprintf(fp, "Readings Above Threshold: %d\n", above_count);

       fclose(fp);

    printf("\nSummary saved to temperature_summary.txt successfully.\n");

     free(temp);

      return 0;
   }

