#include <stdio.h>
float calculateAverage(int *marks, int subjects);
char calculateGrade(float avg);
int find_Topper(float *averages, int students);

int main() {
    int marks[5][3];
    float averages[5];
    int i, j;

    for (i = 0; i < 5; i++) {
        printf("Enter marks of 3 subjects for Student %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        averages[i] = calculateAverage(marks[i], 3);
        printf("Student %d: Average = %.2f, Grade = %c\n", i + 1, averages[i], calculateGrade(averages[i]));
    }

    int (*topper)(float *, int) = find_Topper;
    int topper_student_index = topper(averages, 5);

    printf("\nTopper is Student %d with average %.2f\n", topper_student_index + 1, averages[topper_student_index]);

    return 0;
}

float calculateAverage(int *marks, int subjects) {
    int sum = 0;
    int i;
    for (i = 0; i < subjects; i++) {
        sum += *(marks + i);
    }
    return (float)sum / subjects;
}

char calculateGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

int find_Topper(float *averages, int students) {
    int top_student = 0;
    int i;
    for (i = 1; i < students; i++) {
        if (*(averages + i) > *(averages + top_student)) {
            top_student = i;
        }
    }
    return top_student;
}

