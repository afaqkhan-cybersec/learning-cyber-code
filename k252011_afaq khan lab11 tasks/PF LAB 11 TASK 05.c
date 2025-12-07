#include <stdio.h>

struct File {
    char fileName[100];
    float  o_Size;
    float  r_Rate;
};

float estimateFileSize(struct File file, int k) {
    if (k == 0) { 
        return file.o_Size;
    } else {
        float previousSize = estimateFileSize(file, k - 1);
        float currentSize = previousSize - (previousSize * file.r_Rate);
        return currentSize;
    }
}

int main() {
    struct File file;
    int k; 

    printf("Enter File Name: ");
    scanf("%s", file.fileName);
    
    printf("Enter Original File Size: ");
    scanf("%f", &file.o_Size);
    
    printf("Enter Reduction Rate: ");
    scanf("%f", &file.r_Rate);
    
    printf("Enter Number of Compression Rounds: ");
    scanf("%d", &k);

     float estimated_Size = estimateFileSize(file, k);
     
    printf("\nEstimated file size '%s' after %d compression rounds: %.2f\n", file.fileName, k, estimated_Size);

    return 0;
}

