#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

  typedef struct {
    char student_name[50];
    char roll_number[20];
    int seat_number;
 } student;

  int is_alnum_recursive(char *str,int index) {
    if (str[index]=='\0')
        return 1;
        
    if (!isalnum(str[index]))
        return 0;

    return is_alnum_recursive(str, index + 1);
     }

  void input_roll(char *roll) {
    while (1) {
        printf("enter roll number (alphanumeric only): ");
        scanf("%s", roll);

        if (is_alnum_recursive(roll, 0))
            break;
         else
            printf("invalid! roll must be alphanumeric.\n");
      }
     }

  int main() {
    student *list=NULL;
    int count,add_more,i;

    printf("enter number of students initially: ");
       scanf("%d",&count);
       getchar();

    list=(student *)malloc(count * sizeof(student));
      if (list==NULL) {
        printf("memory allocation failed!\n");
           return 1;
      }

    for (i=0;i<count;i++) {
        printf("\n--- student %d ---\n",i+1);
        printf("enter student name:");
        while (getchar() != '\n');

         scanf("%[^\n]",list[i].student_name);
         
        input_roll(list[i].roll_number);

        printf("enter seat number:");
          scanf("%d", &list[i].seat_number);
        }

    printf("\ndo you want to add more students? enter number (0 for none): ");
    scanf("%d", &add_more);

    if (add_more > 0) {
        list = (student *)realloc(list, (count + add_more) * sizeof(student));
        if (list == NULL) {
            printf("reallocation failed!\n");
            return 1;
        }

        for (i = count; i < count + add_more; i++) {
            printf("\n--- student %d ---\n", i + 1);

            printf("enter student name: ");
              scanf(" %[^\n]", list[i].student_name);

            input_roll(list[i].roll_number);

            printf("enter seat number: ");
              scanf("%d", &list[i].seat_number);
         }

        count +=add_more;
      }

    FILE *fp=fopen("seating.txt", "w");
    if (fp==NULL) {
        printf("file error!\n");
          free(list);
            return 1;
       }

      fprintf(fp,"university exam seating plan\n");

      for (i=0;i<count;i++) {
        fprintf(fp, "student %d:\n",i+1);
        fprintf(fp, "name: %s\n", list[i].student_name);
        fprintf(fp, "roll number: %s\n", list[i].roll_number);
         fprintf(fp, "seat number: %d\n\n", list[i].seat_number);
      }
       fclose(fp);
      printf("\nseating plan saved to seating.txt successfully.\n");
        free(list);
       return 0;
     }

