#include <stdio.h>
#include <stdbool.h>
bool isint( double a){
	int b=a;
	return b==a;
};
int main(){
	double lot;
	printf("entrez un nombre à décomposer: ");
	scanf("%lg",&lot);
	for (double i = 1; i < lot; ++i)
	{
		if (isint(lot/i))
		{
			printf("%g ",i);
		}
	};
	printf("\n");
	return 0;
};
