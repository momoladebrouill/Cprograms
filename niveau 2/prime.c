#include <stdio.h>
#include <string.h>
#define HEIGHT 50
#define MAX_NB_PS 25
int primes[MAX_NB_PS];// On va les rajouter au fur et à mesure qu'on les rencontre

int primerise(int list[HEIGHT][MAX_NB_PS]){
    int nbofprimes=1;
    for(int i=1;i<HEIGHT;i++){ // Pour chaque nombre
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
            if(NoDivs){ 
                list[i][nbofprimes]++;// On le considère comme multiple de himself
                primes[nbofprimes]=i;
                nb=1;
                nbofprimes++;
            }

        }
    }
    return nbofprimes;
}

int main(){
    int list[HEIGHT][MAX_NB_PS]; 
    memset(list,0,sizeof(int)*HEIGHT*MAX_NB_PS);
    int nbofp=primerise(list);
    printf("\033[1;32m");
    for (int i=0;i<nbofp;i++){
        printf("%2i ",primes[i]);
    }
    printf("\033[0m");
    for(int i=0;i<HEIGHT*nbofp;i++){
        if(i%nbofp==0){
            printf("\n%2i ",i/nbofp);
        }else{
            printf(list[i/nbofp][i%nbofp] ? "\033[1;33m%2i\033[0m " : "%2i ",
                    list[i/nbofp][i%nbofp]);
        }
    }
    printf("\nQuantity of primes needed : %i\n",nbofp);
    return 0;
}
