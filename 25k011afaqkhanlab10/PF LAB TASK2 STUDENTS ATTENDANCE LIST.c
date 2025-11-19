#include <stdio.h>
#include <string.h>

 int main() {

    FILE *fp;
     char name[100];
     int count=0;

     fp=fopen("attendance.txt","r");
    if (fp==NULL) {
        printf("Could not open the file attendance.txt\n");
           return 1;
     }
    printf("Student attendance list\n");
    while (fgets(name,sizeof(name),fp)!=NULL) {
        printf("%s",name);
        count++;
      }

    printf("\nTotal students present in file: %d\n",count);

     fclose(fp);
     
    return 0;
}

