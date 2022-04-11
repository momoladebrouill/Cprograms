#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define taille 10

int printls(int *l,size_t len){
    for(int i = 0; i < len; i++){
      printf("%i ", l[i]);
   }
   printf("\n");
   return 0;
}

int * gen(){
   srand(time(NULL));
   static int r[taille];
   for ( int i = 0; i < taille; ++i) {
      r[i] = rand()%69;
   }
   return r;
}

int mergesort(int* ls,size_t size){
  if (size>1) {
    int l1=(int)size/2+size%2;
    int l2=(int)size/2;

    //Gauche
    mergesort(ls,l1);

    //Droite
    int *d=ls+l1;
    mergesort(d,l2);

    //copie avant fusion
    int ancien[size];
    for (size_t i = 0; i < size; i++)ancien[i]=ls[i];

    //fusion, sur ls
    int i=0,j=0,k=0;
    while (i<l1 && j<l2) {
      if (ancien[i]<ancien[l1+j]) {
        ls[k]=ancien[i];
        i++;
      }else{
        ls[k]=ancien[l1+j];
        j++;
      }
      k++;
    }

    while (j<l2) {
      ls[k]=ancien[l1+j];
      j++;
      k++;
    }

    while (i<l1) {
      ls[k]=ancien[i];
      i++;
      k++;
    }
  }
  return 0;
}

int main (){
   int *a=gen();
   printls(a,taille);
   printf("\n");
   mergesort(a,taille);
   printls(a,taille);
   return 0;
}
