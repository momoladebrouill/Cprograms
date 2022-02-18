#include <stdio.h>

int main(){
	int notes[]={1,2,3,4,56,0}; // toutes les valeurs doivent être du même type
	printf("%d\n",notes[sizeof(notes)-1]);
	int vecs[][2]={ //toujours indiquer la longueur des enfants
		{1,2},
		{2,-9},
	};
	printf("%d\n",vecs[0][1]);
	char nom[]="ryan"; // le dernier c'est le stopper \0
	printf("%s %ld\n",nom,sizeof(nom));
	return 0;
}
