#include <stdio.h>
#define WIDTH 24
#define HEIGHT 10

void create(int list[WIDTH][HEIGHT]){
	int nbofprimes=1;
	for(int i=1;i<WIDTH;i++){ // Pour chaque nombre
		list[i][0]=i; // en-tête
		int nb=i; // nombre qui va être divisé dans tous les ens
		while(nb>1){ // tant qu'on ne l'a pas achevé
			int NoDivs=1; // Si il est premier
			for(int j=i-1;j>1;j--){//pour chaque nombre précédent
				if((nb/j)*j==nb){// si nb est divisble par j
					NoDivs=0; // Il n'est donc pas premier
					nb/=j; // on le divise par j
					for(int k=1;k<nbofprimes;++k){list[i][k]+=list[j][k];}
						// On ajoute les diviseurs de celui trouvé
				}
			}
			if(NoDivs){ // Si il est premier
				list[i][nbofprimes]++;// On le considère comme multiple de himself
				nb=1; // Il est premier, ça ne sert à rien de descendre
				nbofprimes++; // logique
			}

		}
	}
}
	
int main(){
		int list[WIDTH][HEIGHT];
		for(int i=0;i<WIDTH*HEIGHT;++i){
			list[i%WIDTH][i/WIDTH]=0;
		}
		create(list);
		const int primes[]={1,2,3,5,7,11,13,17,19,23,29,37}; //juste pour le render tkt
		for(int i=0;i<WIDTH*HEIGHT;i++){
			if(i%WIDTH==0){
				printf("\n\033[1;33m%2i\033[0m ",primes[i/WIDTH]);
			}else{
				printf("%2i ",list[i%WIDTH][i/WIDTH]);
			}
		}	
		return 0;
}