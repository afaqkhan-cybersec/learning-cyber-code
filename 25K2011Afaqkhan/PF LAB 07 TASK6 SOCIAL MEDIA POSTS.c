#include <stdio.h>
int main() {
    int posts[10];
    int i, j;
    int highest = 0, highest_day = 0;
    float total = 0, average;
    int streak_found = 0;
    for (i = 0; i < 10; i++) {
    	printf("Enter the number of posts made on day: %d\n",i+1 );
        scanf("%d", &posts[i]);
        total = total+posts[i];
    }
    highest = posts[0];
    highest_day = 1;
    for (i = 1; i < 10; i++) {
        if (posts[i] > highest) {
            highest = posts[i];
            highest_day = i + 1;
        }
    }
    average = total / 10.0;
    for (i = 0; i < 8; i++) {
        if (posts[i] < posts[i + 1] && posts[i + 1] < posts[i + 2]) {
            streak_found = 1;
            printf("\nIncreasing streak found in ays %d, %d, %d\n", i + 1, i + 2, i + 3);
        }
    }
    printf("\n=====================================\n");
    printf("     Weekly activity report \n");
    printf("=====================================\n");

    printf("Day\tPosts\n");
    for (i = 0; i < 10; i++) {
        printf("%d\t%d\n", i + 1, posts[i]);
    }

    printf("-------------------------------------\n");
    printf("Highest activity day is %d (%d posts)\n", highest_day, highest);
    printf("Average daily posts: %.2f\n", average);

    if (streak_found==0) {
        printf("No 3 days increasing activity streak found.\n");
    }

    return 0;
}

