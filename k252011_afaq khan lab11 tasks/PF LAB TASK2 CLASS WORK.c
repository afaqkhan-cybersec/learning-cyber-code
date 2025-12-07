#include <stdio.h>

  struct Route {
    int routeID;
    float distance;
    float basePrice;
    int roadType;
  };

  float getCharge(int type) {
    if (type == 1) return 50;
    if (type == 2) return 80;
    return 120;
  }

   void calculateCostRecursive(float distance, float base, int type, float *totalCost) {
      if (distance <= 0)
          return;

      *totalCost += base + getCharge(type);
    
        calculateCostRecursive(distance - 10, base, type, totalCost);
   }

   int main() {
     struct Route R;
      float finalCost = 0;

      printf("Enter Route ID ");
        scanf("%d", &R.routeID);

       printf("Enter Distance (km) ");
        scanf("%f", &R.distance);

       printf("Enter Base Price per 10 km ");
       scanf("%f", &R.basePrice);

       printf("Enter Road Type (1=Highway, 2=City, 3=Off-road): ");
       scanf("%d", &R.roadType);

       calculateCostRecursive(R.distance, R.basePrice, R.roadType, &finalCost);

    printf("\n---- FINAL ROUTE COST ----\n");
    printf("Route ID: %d\n", R.routeID);
    printf("Total Distance: %.2f km\n", R.distance);
    printf("Final Delivery Cost: %.2f\n", finalCost);

    return 0;
}

