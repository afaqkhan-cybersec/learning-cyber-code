#include <stdio.h>
#include <string.h>
  int main() {
    char password[100];
    int length;
    int special=0;
    int i;
    
    char specialchars[]="!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";
    
    printf("Enter your password: ");
     fgets(password,sizeof(password),stdin);
      password[strcspn(password,"\n")]='\0';
       length=strlen(password);

    for (i =0;i<strlen(specialchars);i++) {
        if (strchr(password,specialchars[i])!= NULL) {
            special=1;
            break;
         }
      }
    if (length< 6) {
        printf("Password Strength: Weak\n");}
    else if (length >=6 &&length< 10) {
        if (special)
            printf("Password Strength: Medium\n");
        else
            printf("Password Strength: Weak\n");
      }
    else {
        if (special)
            printf("Password Strength: Strong\n");
        else
            printf("Password Strength: Medium\n");
    }

    return 0;
}

