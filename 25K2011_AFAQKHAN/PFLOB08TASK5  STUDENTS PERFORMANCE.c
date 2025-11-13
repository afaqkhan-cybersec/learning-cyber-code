#include <stdio.h>

int main() {
    int marks[2][3][3];
    int total[2][3];
    int class_topper[2];
    int class_topper_marks[2];
    int i;
    int j;
    int k;

    for (i = 0; i< 2; i++) {
        printf("Class %d\n", i+ 1);
    for (j = 0; j< 3; j++) {
        printf("  Student %d:\n", j + 1);
     for (k = 0; k < 3; k++) {
        printf(" Subject %d marks: ", k+ 1);
        scanf("%d", &marks[i][j][k]);
         }
         }
      }

    for (i= 0; i< 2; i++) {
        for (j = 0; j < 3; j++) {
            int sum = 0;
        for (k = 0; k< 3; k++) {
                sum += marks[i][j][k];
        }
            total[i][j] = sum;
        }
    }
    
    for (i = 0; i< 2; i++) {
        int max_marks = total[i][0];
        int topper = 0;
        for (j= 1; j< 3; j++) {
            if (total[i][j] > max_marks) {
                max_marks = total[i][j];
                topper = j;
        }
        }
        class_topper[i] = topper;
        class_topper_marks[i] = max_marks;
    }
    
    int overall_class = 0;
    if (class_topper_marks[1] > class_topper_marks[0]) {
        overall_class = 1;
    }
    int overall_student = class_topper[overall_class];
    int overall_marks = class_topper_marks[overall_class];
    
    printf("\n-------------------- RESULTS --------------------\n");
    for (i = 0;i< 2;i++) {
        printf("Top Performer of Class %d: Student %d with %d marks\n",
               i + 1, class_topper[i] + 1, class_topper_marks[i]);
    }

    printf("\nOverall Top Performer: Class %d, Student %d with %d marks\n",
           overall_class + 1, overall_student + 1, overall_marks);

    return 0;
}

