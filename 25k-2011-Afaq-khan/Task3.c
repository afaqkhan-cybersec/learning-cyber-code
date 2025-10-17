#include<stdio.h>
main(){
	float distance;
	float liters;
	float ppl; // price per litre

    printf("inter distance travelled \n");
    scanf("%f", &distance);
    
    printf("inter liters consumed \n");
    scanf("%f", &liters);
    
    printf("inter price per litre \n");
    scanf("%f", &ppl);
    
    float efficiency= distance/liters;
    float total_cost=liters*ppl;
    
    
    printf("\n===============================\n");
    printf(" FUEL REPORT \n");
    printf("\n===============================\n");
    printf(" Distance: %.2f", distance);
    printf("Km\n");
    printf(" Fuel used: %.2f", liters);
    printf("L\n");
    printf(" Effeciency: %.2f",efficiency );
    printf(" km/L\n");
    printf(" Total cost: %.2f",total_cost );
    printf(" PKR\n");
    return 0;
}
