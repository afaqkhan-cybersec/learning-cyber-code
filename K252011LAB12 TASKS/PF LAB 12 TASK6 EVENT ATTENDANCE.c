#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 int total_recursive(int *arr,int index,int size) {
    if (index==size)
        return 0;

    return arr[index] +total_recursive(arr,index +1,size);
   }

  int main() {
     int count,add_more, i;

     printf("Enter number of gates initially: ");
       scanf("%d",&count);

    int *gates =(int *)malloc(count * sizeof(int));
      if (gates==NULL) {
         printf("Memory allocation failed!\n");
          return 1;
        }

    for (i=0;i<count;i++) {
        printf("Enter attendance for Gate %d: ",i+1);
          scanf("%d",&gates[i]);
       }

    printf("\nDo you want to add more gates? Enter number 0 for none");
    scanf("%d",&add_more);

    if (add_more>0) {
        gates=(int *)realloc(gates,(count + add_more) * sizeof(int));

        if (gates == NULL) {
             printf("Memory reallocation failed!\n");
              return 1;
        }

        for (i = count; i< count+add_more;i++) {
            printf("Enter attendance for new Gate %d: ", i + 1);
              scanf("%d",&gates[i]);
        }

        count +=add_more;
      }

    int total=total_recursive(gates,0,count);

    int highest=gates[0];
      int gate_no=1;

     for (i=1;i<count;i++) {
        if (gates[i] >highest) {
            highest=gates[i];
             gate_no=i+1;
        }
       }

    FILE *fp=fopen("attendance.txt","w");
     if (fp==NULL) {
        printf("File creation error!\n");
         free(gates);
            return 1;
     }

      time_t current_time;
       time(&current_time);
        char *timestamp=ctime(&current_time);

    fprintf(fp, "Event Attendance Report\n");
     fprintf(fp,"Generated on: %s\n\n",timestamp);

    for (i=0;i<count;i++) {
         fprintf(fp,"Gate %d: %d attendees\n",i+1,gates[i]);
      }

    fprintf(fp, "\nTotal Attendees (recursive): %d\n",total);
     fprintf(fp,"Gate with highest attendance: Gate %d (%d attendees)\n", gate_no,highest);

    fclose(fp);

      printf("\nAttendance saved to attendance.txt successfully.\n");

     free(gates);
      return 0;
   }

