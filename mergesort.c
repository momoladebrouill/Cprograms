#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define taille 10

void printls(int *l,size_t len){
    for ( int i = 0; i < len; i++ ) {
      printf( "%i\t",l[i]);
   }
   printf("\n");
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

    //Droite
    int *d=ls+mid;
    mergesort(d,mid);

    //copie avant fusion
    int ancien[size];
    for (size_t i = 0; i < size; i++)ancien[i]=ls[i];

    //fusion, sur ls
    int i=0,j=0,k=0;
    while (i<mid && j<mid) {
      if (ancien[i]>ancien[mid+j]) {
        ls[k]=ancien[i];
        i++;
      }else{
        ls[k]=ancien[mid+j];
        j++;
      }
      k++;
    }

    while (j<mid) {
      ls[k]=ancien[mid+j];
      j++;
      k++;
    }
    while (i<mid) {
      ls[k]=ancien[i];
      i++;
      k++;
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
