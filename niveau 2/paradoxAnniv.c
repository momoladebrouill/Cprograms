#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUM_OF_PPL 23
#define NUM_OF_TRY 1000

// 23 anniversaires
// proba d'au moins 2 anniversaires similaires
// normalement on devrait avoir environ 0.51

// ça revient à la proba que l'on tire deux fois le même nombre dans un jeu qui contient 365 cartes et qu'on tire 23 fois les cartes


void generate(int * ppl){
	for(int i=0;i<NUM_OF_PPL;i++){
        ppl[i]=(rand()%12)*100+(rand()%31);
        // ppl[i]=MMDD
	}	
}

int samebdys(int * ppl){
	for(int a=0;a<NUM_OF_PPL;a++){
		for(int b=0;b<NUM_OF_PPL;b++){
			if((ppl[a]==ppl[b])&&(a!=b)){
				return 1;
			}
        }
	}
	return 0;
}

int main(){
	srand(time(NULL));
	int ppl[NUM_OF_PPL];
    int sames=0;
    for(int i=0;i<NUM_OF_TRY;i++){
        generate(ppl);
        sames+=samebdys(ppl);
    }
	printf("N of sames : %f\n",((float)sames)/((float)NUM_OF_TRY));
	return 0;
}
