#include <stdio.h>
#include <math.h>

int main() {
    int age;
    float account_balance;
    int ride_type;
    char distance;
    int requests;
    int loyalty_points;
    int driver_rating;
    float driver_distance;

    float base_fare = 0, surge_multiplier, final_fare, discounted_final_fare;
    float discount;
    char *driver_status;
    char *ride_name;

    //Passenger eligibility
    printf("enter your age:\n");
    scanf("%d", &age);
    printf("enter your account balance:\n");
    scanf("%f", &account_balance);

    if (age < 21) {
        printf("Not eligible for ride (underage)\n");
        return 0;
    } 
    else if (account_balance < 200) {
        printf("Not eligible (insufficient balance)\n");
        return 0;
    }

    printf("Eligible for ride\n");

    //Ride type selection
    printf("please enter ride type(1..3)\n");
    scanf("%d", &ride_type);

    printf("please enter distance(S/L)\n");
    scanf(" %c", &distance);

    switch(ride_type){
        case 1:
            ride_name = "Economy";
            if (distance == 'S' || distance == 's'){
            	 base_fare =100;
			}
			else{
				base_fare =300;
			}
            break;
        case 2:
            ride_name = "Business";
            if (distance == 'S' || distance == 's'){
            	 base_fare =100;
			}
			else{
				base_fare =300;
			}
            break;
        case 3:
            ride_name = "Luxury";
            if (distance == 'S' || distance == 's'){
            	 base_fare =100;
			}
			else{
				base_fare =300;
		}
            break;
        default:
            printf("Wrong ride type\n");
            return 0;
    }

    //Surge multiplier
    printf("enter number of requests\n");
    scanf("%d", &requests);

    surge_multiplier = sqrt(requests) / 2;
    if (surge_multiplier > 3)
        surge_multiplier = 3;

    //Apply surge to fare
    final_fare = base_fare * surge_multiplier;

    //Discount
    printf("please enter your loyalty points\n");
    scanf("%d", &loyalty_points);
    discount = (loyalty_points > 1000) ? 0.2 : 0.05;
    discounted_final_fare = final_fare-final_fare*discount;

    //Driver assignment
    printf("enter driver rating(1..5):\n");
    scanf("%d", &driver_rating);
    printf("enter passenger distance from driver:\n");
    scanf("%f", &driver_distance);

    if(driver_rating >= 4 && driver_distance <= 5)
        driver_status = "Top driver nearby";
    else if(driver_rating >= 3 && driver_distance <= 10)
        driver_status = "Average driver assigned";
    else
        driver_status = "No suitable driver available";

    //Final ride summary
    printf("\n--- Ride Summary ---\n");
    printf("Passenger eligible\n");
    printf("Ride type: %s\n", ride_name);
    printf("Driver assigned: %s\n", driver_status);
    printf("Final fare after surge and discount: %.2f\n", discounted_final_fare);

    return 0;
}
