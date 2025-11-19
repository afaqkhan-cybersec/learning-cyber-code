#include <stdio.h>
#include <string.h>

int main() {
    char str1[100],str2[100],combined[200];

    printf("Enter first string:");
    fgets(str1,sizeof(str1),stdin);
    str1[strcspn(str1,"\n")] ='\0'; 

    printf("Enter second string:");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")]='\0';

    if (strcmp(str1, str2)==0)
        printf("Both strings are the SAME.\n");
    else
        printf("Both strings are DIFFERENT.\n");
    strcpy(combined,str1);
    strcat(combined, " ");
    strcat(combined,str2);

    printf("Joined String: %s\n",combined);

    return 0;
}

