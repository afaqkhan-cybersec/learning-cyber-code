#include <stdio.h>

int main() {
    int base, exponent, i;
    int result;
    printf("Enter base\n");
    scanf("%d", &base);

    printf("Enter non-negative exponent\n");
    scanf("%d", &exponent);
    
    if (exponent < 0) {
        printf("Exponent must be non-negative\n");
    }
	else {
	
	  for (i = 1; i <= exponent; i++){
        result = result * base;
		}
        
    printf("The result is=%d\n",result);}

    return 0;
}
