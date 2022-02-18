#include <stdio.h>

int main(){
	int lot;
	printf("entrez un nombre à décomposer: ");
	scanf("%i",&lot);
	for (int i = 1; i < lot; i++){
		if ((lot/i)*i ==lot){
			printf("%i\n",i);
		}
	};
	printf("\n");
	return 0;
};
