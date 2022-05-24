#include <stdio.h>
#define WIDTH 10
#define HEIGHT 10
//2,3,5,7,11,13,17,19,23,29,37 ...
const int primes[]={1,2,3,5,7,11,13,17,19,23,29,37};
void create(int list[10][10]){
	for(int i=1;i<10;i++){
		list[i][0]=i;
		for(int j=1;j<HEIGHT;j++){
			int nb=0;
			int div=primes[j];
			while((i/div)*div==i){// tant que i est divisible par nb
				nb++;// c'est qu'il est encore divible
				div=div*primes[j];//donc on augmente la puissance
			}
			list[i][j]=nb;
		}	
	}
}
	
int main(){
		int list[WIDTH][HEIGHT];
		for(int i=0;i<WIDTH*HEIGHT;++i){
			list[i%10][i/10]=0;
		}
		create(list);
		for(int i=0;i<100;i++){
			if(i%10==0){printf("\n");}
			printf("%i\t",list[i%10][i/10]);
		}	
		return 0;
}