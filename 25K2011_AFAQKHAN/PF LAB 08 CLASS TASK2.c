#include <stdio.h>
int main() {
    int bed[4][6];
    int i, j;
	int total_occupied = 0;
	int total_vacant = 0;
    int ward_occupied[4];
	int max_ward = 0; 
	int max_value = 0;
    for (i = 0; i < 4; i++) {
        printf("Enter 1 for occupied or 0 for vacant for Ward %d:\n", i + 1);
        ward_occupied[i] = 0;
        for (j = 0; j < 6; j++) {
            scanf("%d", &bed[i][j]);
            if (bed[i][j] == 1) {
                total_occupied++;
                ward_occupied[i]++;
            } else {
                total_vacant++;
           }
          }
    }
    for (i = 0; i < 4; i++) {
        if (ward_occupied[i] > max_value) {
            max_value = ward_occupied[i];
            max_ward = i;
        }
    }
    float total_beds = 4 * 6;
    float occupancy_rate = (total_occupied / total_beds) * 100;
    printf("\nTotal occupied beds: %d", total_occupied);
    printf("\nTotal vacant beds: %d", total_vacant);
    printf("\nWard %d has maximum occupancy (%d beds)", max_ward + 1, max_value);
    if (occupancy_rate < 60)
        printf("\nIncrease Admission Drive\n");
    else
        printf("\nOccupancy satisfactory\n");
    return 0;
}

