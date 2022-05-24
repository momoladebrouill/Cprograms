#include <stdio.h>
#define WIDTH 24
#define HEIGHT 10
//2,3,5,7,11,13,17,19,23,29,37 ...
const int primes[]={1,2,3,5,7,11,13,17,19,23,29,37};
void create(int list[WIDTH][HEIGHT]){
	int nbofprimes=1;
	for(int i=1;i<WIDTH;i++){
		list[i][0]=i;
		int nb=i;
		while(nb>1){
			int NoDivs=1;
			for(int j=i-1;j>1;j--){//pour chaque nombre précédent
				if((nb/j)*j==nb){// si nb est divisble par j
					nb/=j; //on le divise par j
					NoDivs=0;
					for(int k=1;k<HEIGHT;++k){list[i][k]+=list[j][k];}
						// On ajoute les diviseurs de celui trouvé
				}
			}
			if(NoDivs){
				list[i][nbofprimes]++;
				nb/=nb;
				nbofprimes++;
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
		for(int i=0;i<WIDTH*HEIGHT;i++){
			if(i%WIDTH==0){
				printf("\n\033[1;33m%2i\033[0m ",primes[i/WIDTH]);
			}else{
				printf("%2i ",list[i%WIDTH][i/WIDTH]);
			}
		}	
		return 0;
}