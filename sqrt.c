#include <stdio.h>

int main(){
	int car;
	printf("Bon, c'est pas top mais il vaut des talents de Hacker là\n");
	printf("Entrez le nombre : ");
	scanf("%i",&car);
	double preci=1e-8;
	double sq=2;
	double ec=100;
	if (car<0)
	{
		printf("Heergg ma pa possibile\n");
	}else{
		while((sq*sq)!=car && ec>(preci*10))
		{
			if((sq*sq)>car)
			{
				sq=sq-preci;
			}else{
				sq=sq+preci;
			};
			//printf("Recherche : %g² = %g ecart: %g\n",sq,sq*sq,ec);
			ec=sq*sq-car;
			if (ec<=0)
			{
				ec=ec*(-1);
			};
		};
		printf("La racine de %i est %g\n",car,sq);
	};
	return 0;
};