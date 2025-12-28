#include <stdio.h>

int main() {
    float temperature[3][3][3];
    float house_avg[3];
    float sum;
    float max_temperature;
    int max_house = 0;
    int max_i = 0, max_j = 0, max_z = 0;
    int z;
    int i;
    int j;
    for (z=0; z < 3; z++) {
        printf("\nEnter temperature for house %d\n", z + 1);
        for (i= 0; i < 3; i++) {
          for (j= 0; j < 3; j++) {
        printf("Temperature for house %d, at Row %d, Col %d: ", z + 1, i + 1, j + 1);
            scanf("%f", &temperature[z][i][j]);
          }
         }
    }
    
    for (z = 0; z < 3; z++) {
        sum = 0;
     for (i = 0; i < 3; i++) {
          for (j = 0; j < 3; j++) {
        sum = sum+temperature[z][i][j];
            }
        }
        house_avg[z]= sum/9;
    }
   
   for (z = 1; z < 3; z++) {
        if (house_avg[z] > house_avg[max_house]) {
            max_house=z;
      }
     }

    max_temperature=temperature[0][0][0];
    for (z = 0; z < 3; z++) {
     for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
      if (temperature[z][i][j] > max_temperature) {
          max_temperature=temperature[z][i][j];
             max_i=i;
             max_j=j;
             max_z=z;
        }
    }
   }
 }
printf("\nHouse Averages:\n");
    for (z = 0; z < 3; z++) {
        printf("house %d average = %.2f\n", z + 1, house_avg[z]);
    }
    printf("\nHottest house is house %d with average temperature = %.2f\n",
           max_house + 1, house_avg[max_house]);
    printf("Maximum Temperature: %.2f is at Row %d, Column %d, Layer %d\n",
           max_temperature, max_i + 1, max_j + 1, max_z + 1);
    return 0;
}

