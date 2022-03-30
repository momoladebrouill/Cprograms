#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define taille 10

void printls(int *l,size_t len){
    for ( int i = 0; i < len; i++ ) {
      printf( "%d %i\n", i,l[i]);
   }
}

int * gen(){
   static int r[taille];
   for ( int i = 0; i < taille; ++i) {
      r[i] = rand()%50;
   }
   return r;
}

void mergesort(int* ls,size_t size){
  if (size>1) {
    int mid=(int)size/2;
    //Gauche
    mergesort(ls,mid);
    //droite
    int *d;
    d=ls+mid;
    mergesort(d,mid);
    int i=0,j=0;

    //fusion
    while (i<mid && j<mid) {
      if (ls[i]<ls[mid+j]) {
        i++;
      }else{
        ls[i]=ls[mid+j];
        j++;
      }
    }
    while (j<mid) {
      ls[i]=ls[mid+j];
      j++;
    }
  }
}

int main (){
   int *a;
   srand(time(NULL));
   a=gen();
   printls(a,taille);
   printf("zzzzzzz\n");
   mergesort(a,taille);
   printls(a,taille);
   return 0;
}
