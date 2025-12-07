#include <stdio.h>
#include <stdlib.h>

  int main() {
      int hours,newhours;
      int threshold;
      int i;

    printf("Enter initial hours ");
    scanf("%d", &hours);

     int *steps=(int *)malloc(hours * sizeof(int));
      if (steps==NULL) {
        printf("Memory allocation failed!\n");
           return 1;
      }
      
    printf("\nEnter step count for each hour:\n");
    for (i=0; i<hours; i++) {
        printf("Hour %d: ", i + 1);
          scanf("%d",(steps +i));
    }

    printf("\nDo you want to add more hours? Enter number 0 for none:");
    scanf("%d",&newhours);

    if (newhours> 0) {
        steps=(int *)realloc(steps,(hours+newhours) * sizeof(int));
           if (steps==NULL) {
            printf("Reallocation failed!\n");
               return 1;
          }

        printf("\nEnter step count for the additional hours:\n");
        for (i=hours;i<hours+newhours;i++) {
            printf("Hour %d:",i+1);
            scanf("%d",(steps+i));
    }
        hours +=newhours;
     }

    int max = *(steps + 0);
     int total=0;
        int abovecount=0;

    printf("\nEnter threshold for high step hours: ");
        scanf("%d", &threshold);

    for (i=0;i<hours;i++) {
        int val= *(steps + i);

        total += val;
        if (val>max) 
		 max =val;
          if (val>threshold) 
	     	abovecount++;
     }

    printf("\n===== Fitness Tracker Analysis=====\n");
    printf("Total Hours Recorded: %d\n", hours);
    printf("Total Steps: %d\n", total);
    printf("Maximum Steps in an Hour: %d\n", max);
    printf("Hours Above Threshold (%d) is %d\n", threshold, abovecount);

    FILE *fp=fopen("fitness_tracker.txt","w");
    if (fp==NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "Fitness Tracker Data\n");
    fprintf(fp, "Total Hours: %d\n", hours);
    fprintf(fp, "Steps per Hour:\n");

    for (i=0; i<hours; i++) {
        fprintf(fp, "Hour %d: %d\n",i+1, *(steps+i));
    }

    fprintf(fp, "Total Steps: %d\n",total);
    fprintf(fp, "Maximum Steps: %d\n",max);
    fprintf(fp, "Hours above %d: %d\n",threshold,abovecount);

    fclose(fp);

    printf("\nData saved to fitness_tracker.txt successfully.\n");

    free(steps);
        return 0;
      }

