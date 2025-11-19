#include <stdio.h>
#include <string.h>

int main() {
    char names[10][50];
    char temp[50];
    int i,j;
    
    printf("Enter 10 student names:\n");
    for (i =0; i <10; i++) {
        printf("Name %d: ", i + 1);
     fgets(names[i],sizeof(names[i]), stdin);

        names[i][strcspn(names[i], "\n")] ='\0';
    }
    for (i = 0; i<9;i++) {
        for (j = i+ 1; j<10; j++) {
            if (strcmp(names[i], names[j])> 0) {
            strcpy(temp, names[i]);
            strcpy(names[i], names[j]);
            strcpy(names[j], temp);
            }
          }
   } 
    printf("\nNames in Alphabetical Order:\n");
    for (i = 0; i < 10; i++) {
        printf("%s\n", names[i]);
    }
    return 0;
}


