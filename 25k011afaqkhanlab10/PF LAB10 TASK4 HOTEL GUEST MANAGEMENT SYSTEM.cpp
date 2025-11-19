 #include <stdio.h>
 #include <string.h>

  int main() {
    FILE *fp;
    char guests[50][50];
     int rooms[50];
     int n, i;
     char search[50];
     int found = 0;

    printf("Enter number of bookings: ");
      scanf("%d",&n);

    for (i =0; i< n;i++) {
        printf("\nEnter name of guest %d\n", i + 1);
        scanf("%s",guests[i]);

        printf("Enter room number");
        scanf("%d",&rooms[i]);
       }

    fp =fopen("hotel.txt","w");
     if (fp == NULL) {
         printf("Error...file not opening\n");
         return 1;
      }
    for (i = 0; i<n; i++) {
        fprintf(fp,"%s %d\n",guests[i], rooms[i]);
       }

    fclose(fp);
    printf("\nRecords saved successfully in hotel.txt\n");

    printf("\nEnter guest name to search\n");
    scanf("%s",search);

    fp =fopen("hotel.txt","r");
    if (fp== NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    char name[50];
     int room;
       found = 0;

    while (fscanf(fp,"%s %d",name,&room)!=EOF) {
        if (strcmp(name, search) == 0) {
            printf("Guest %s has room number: %d\n", name, room);
              found=1;
                 break;
            }
         }
    if (!found) {
        printf("Guest %s not found\n", search);
       }

      fclose(fp);

           return 0;
    }

