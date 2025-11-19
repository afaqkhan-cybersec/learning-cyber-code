#include <stdio.h>
#include <string.h>

int main() {
    char books[10][100];
    char search[100];
    int found=0;
    int i;
    
    printf("Enter 10 book titles:\n");
     for(i=0; i<10;i++) {
        printf("Book %d\n",i+1);
        fgets(books[i],sizeof(books[i]), stdin);

        books[i][strcspn(books[i],"\n")]='\0';
       }

    printf("\nEnter the book title to search");
    fgets(search, sizeof(search),stdin);
       search[strcspn(search, "\n")]='\0';

      for (i =0; i <10;i++) {
         if (strcmp(books[i],search)==0) {
            found = 1;
             break;
         }
      }

     if (found)
        printf("Book Found\n");
      else
         printf("Book Not Found!\n");

     return 0;
  }

