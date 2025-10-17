#include <stdio.h>

int main() {
    int townA = 10000;
    int townB = 8000;
    int years = 0;
    while (townB <= townA) {
        townA += 250;  
        townB += 400;  
        years++;
    }
    printf("After %d years:\n", years);
    printf("Town A population = %d\n", townA);
    printf("Town B population = %d\n", townB);

    return 0;
}

