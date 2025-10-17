#include <stdio.h>
int main()
{
int ride_type;
char distance;
printf("please enter ride type(1..3)\n");
scanf("%d",&ride_type);

switch(ride_type){
	
case 1:
		printf("please enter distance(S/L)\n");
        scanf(" %c",&distance);
	switch(distance){
	case 's':
	case 'S':
		printf("Economy\n");
		printf("Base fare=100\n");
		break;
	case 'l':
	case 'L':
		printf("Economy\n");
		printf("Base fare=300\n");
		break;
	default:
		printf("Wrong distance\n");
	
}
	break;
case 2:
		printf("please enter distance(S/L)\n");
        scanf(" %c",&distance);
	switch(distance){
	case 's':
	case 'S':
		printf("Business\n");
		printf("Base fare=100\n");
		break;
	case 'l':
	case 'L':
		printf("Business\n");
		printf("Base fare=300\n");
		break;
	default:
		printf("Wrong distance\n");
	
}
	break;
case 3:
		printf("please enter distance(S/L)\n");
        scanf(" %c",&distance);
	switch(distance){
	case 's':
	case 'S':
		printf("Luxury\n");
		printf("Base fare=100\n");
		break;
	case 'l':
	case 'L':
		printf("Luxury\n");
		printf("Base fare=300\n");
		break;
	default:
		printf("Wrong distance\n");
	
}
	break;
	default:
		printf("Wrong ride type\n");
	return 0;
}
}
