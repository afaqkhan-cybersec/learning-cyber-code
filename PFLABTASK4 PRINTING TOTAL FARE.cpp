#include <stdio.h>
#include <math.h>

int main() {
    char ride_type;
    int distance, requests;
    float surge_multiplier, total_fare;
    
    printf("Enter ride type (E for Economy, B for Business, L for Luxury)");
    scanf(" %c", &ride_type);

    printf("Enter distance in (km)");
    scanf("%d", &distance);

    printf("Enter number of ride requests in area");
    scanf("%d", &requests);
	 
    surge_multiplier = sqrt(requests) / 2;
    if (surge_multiplier > 3)
        surge_multiplier = 3;
        
    switch (ride_type) {
        case 'E':
        case 'e':
            total_fare = (50 * distance) * surge_multiplier;
            printf("Ride type is Economy\n");
            printf("total fare is %.2f\n",total_fare);
            break;

        case 'B':
        case 'b':
            total_fare = (100 * distance) * surge_multiplier;
            printf("Ride type is Business\n");
            printf("total fare is %.2f\n",total_fare);
            break;

        case 'L':
        case 'l':
            total_fare = (200 * distance) * surge_multiplier;
            printf("Ride type is Luxury\n");
            printf("total fare is %.2f\n",total_fare);
            break;

        default:
            printf("Invalid ride type entered\n");
            return 0;
    }

    return 0;
}

