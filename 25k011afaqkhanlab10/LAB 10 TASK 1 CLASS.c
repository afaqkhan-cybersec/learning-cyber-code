#include <stdio.h>
#include <string.h>

int main() {
    char msg[200];
    char updated[200];
    char *pos;

    printf("Enter customer feedback message: ");
    gets(msg);

    printf("Total number of characters: %d\n",strlen(msg));

    if (strstr(msg,"bad"))
        printf("The word (bad) is in the message.\n");
    else
        printf("The word (bad) is not in the message.\n");

    if (strstr(msg, "good"))
        printf("The word (good) is in the message.\n");
    else
        printf("The word (good) is not in the message.\n");

    pos = strstr(msg, "bad");
    if (pos) {
 
    strncpy(updated,msg,pos-msg);
        updated[pos - msg] = '\0';

        strcat(updated,"not good");

         strcat(updated,pos+ 3);

        printf("Updated message: %s\n", updated);
    } else {
        printf("No change needed: %s\n", msg);
    }
    return 0;
}

