#include <stdio.h>

void bookSeat(int *seats, int seatNo, int totalSeats);
void cancelSeat(int *seats, int seatNo, int totalSeats);
void displaySeats(int *seats, int totalSeats, int flightNo);

int main() {
    int flight1[5] = {0};
    int flight2[7] = {0};
    int flight3[9] = {0};

    int choice;
    int flightNo;
    int seatNo;

    while (1) {
        printf("\n--- Flight Seat Booking System ---\n");
        printf("1. Book a seat\n");
        printf("2. Cancel a seat\n");
        printf("3. Display booked seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        if (choice == 1) {
            printf("Enter flight number (1-3): ");
            scanf("%d", &flightNo);

            if (flightNo < 1 || flightNo > 3) {
                printf("Invalid flight number!\n");
                continue;
            }

            printf("Enter seat number: ");
            scanf("%d", &seatNo);

            if (flightNo == 1) {
                bookSeat(flight1, seatNo, 5);
           } else if (flightNo == 2) {
                bookSeat(flight2, seatNo, 7);
               }else if (flightNo == 3) {
                bookSeat(flight3, seatNo, 9);
            }

        } else if (choice == 2) {
            printf("Enter flight number (1-3): ");
            scanf("%d", &flightNo);

            if (flightNo < 1 || flightNo > 3) {
           printf("Invalid flight number!\n");
                continue;
            }

         printf("Enter seat number: ");
            scanf("%d", &seatNo);

            if (flightNo == 1) {
                cancelSeat(flight1, seatNo, 5);
            } else if (flightNo == 2) {
                cancelSeat(flight2, seatNo, 7);
         } else if (flightNo == 3) {
             cancelSeat(flight3, seatNo, 9);
            }

        } else if (choice == 3) {
            displaySeats(flight1, 5, 1);
            displaySeats(flight2, 7, 2);
            displaySeats(flight3, 9, 3);
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
    
}


void bookSeat(int *seats, int seatNo, int totalSeats) {
    if (seatNo < 1|| seatNo >totalSeats) {
        printf("Invalid seat number!\n");
        return;
      }
      if (*(seats +seatNo- 1) == 1) {
        printf("Seat already booked!\n");
    } else {
        *(seats + seatNo- 1)= 1;
      printf("Seat %d booked successfully!\n",seatNo);
    }
}
void cancelSeat(int *seats,int seatNo,int totalSeats) {
    if (seatNo <1 ||  seatNo >totalSeats) {
        printf("Invalid seat number!\n");
        return;
    }

    if (*(seats + seatNo - 1) == 0) {
        printf("Seat is not booked!\n");
    } else {
        *(seats + seatNo - 1) = 0;
     printf("Seat %d cancelled successfully!\n", seatNo);
    }
}
void displaySeats(int *seats, int totalSeats, int flightNo) {
 int count = 0;
 int i;
  for (i = 0; i < totalSeats; i++) {
         if (*(seats + i) == 1) {
        count++;
        }
    }
    printf("Flight %d: %d seats booked out of %d\n", flightNo,count, totalSeats);
}

