#include <math.h>
#include <stdio.h>
#include <stdbool.h>
int main()
{
	printf("%g\n",exp(1));
	int x=5;
	printf("%i\n",x);
	printf("%i\n",6%2);
	x/=2;
	x++;
	double c= (double)25/2*2;

	printf("%f\n",(double)x);
	printf("%f\n",(double)17/2 );
	printf("%f\n",c );
	printf("%d\n",1!=2);
	x++;
	switch(x)
	{
		case 1:
			printf("qu'un seul\n");
			break;
		case 2:
			printf("et de deux\n");
			break;
		case 3:
			printf("jamais deux sans trois\n");
			break;
		default:
			printf("%s\n","mmmh je sais pas" );
	}
	printf("%f\n",(double)1/0);
	return 0;
}
