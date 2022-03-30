#include <stdio.h>
#include <stdlib.h>
#define taille 10

int * gen(){
   static int r[taille];
   for ( int i = 0; i < taille; ++i) {
      r[i] = rand()%50;
   }
   return r;
}

void bubblesort(int *l,size_t len){
    int ismexe=1;
    while(ismexe){
        ismexe=0;
        for(size_t i=0;i<len-1;i++){
            if(l[i]>l[i+1]){
                ismexe=1;
                l[i]=l[i]^l[i+1];
                l[i+1]=l[i]^l[i+1];
                l[i]=l[i]^l[i+1];
            }
        }
    }
}

void printls(int *l,size_t len){
    for ( int i = 0; i < len; i++ ) {
      printf( "%d %i\n", i,l[i]);
   }
}

int main (){
   int *a;
   a=gen();
   printf("avant\n");
   printls(a,taille);

   bubblesort(a,taille);

   printf("apres\n");
   printls(a,taille);
   return 0;
}
