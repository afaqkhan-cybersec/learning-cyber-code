#include<stdio.h>
int main() {
int seats[10][4];
int reserved_row,reserved_coloumn, reserved;
int full_row=0;
int i;
int j;
    
      for(i=0;i<10;i++){
      	for(j=0;j<4;j++){
      		 seats[i][j]=0;
		  }
	  }
	  printf("Plese enter the number of seat you want to reserve(1...40)\n");
	  scanf("%d",&reserved);
	  
	  for(i=0;i<reserved;i++){
	  	printf("enter the row you want to reserve(1...10)\n");
	  	scanf("%d",&reserved_row);
	  	printf("enter the coloumn you want to reserve(1...4)\n");
	  	scanf("%d",&reserved_coloumn);
	  	
	  	  if(reserved_row<1||reserved_row>10||reserved_coloumn<1||reserved_coloumn>4){
      	printf("invalid seat number please enter another one\n");
		  }
      	  else if(seats[reserved_row-1][reserved_coloumn-1]==1){
    	printf("The seat is already reserved please enter another one\n");
		}
		else{
		seats[reserved_row-1][reserved_coloumn-1]=1;
	   }
	  }
      printf("\nSeat Map (1 = Reserved, 0 = Available):\n");
      for (i = 0; i < 10; i++) {
        printf("Row %2d: ", i + 1);
        for (j = 0; j < 4; j++) {
            printf("%d ", seats[i][j]);
        }
        printf("\n");
    }  
    for (i = 0; i < 10; i++) {
        int full_row = 1;
        for (j = 0; j < 4; j++) {
            if (seats[i][j] == 0) {
                full_row = 0;
                break;
            }
        }
        if (full_row)
            full_row++;
    }
    printf("\nNumber of fully booked rows: %d\n", full_row);
return 0;
}







