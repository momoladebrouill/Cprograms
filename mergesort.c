#include <stdio.h>
#include <stdlib.h>
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

int * fusion(int * rendu, int * l1,int*l2, int lenght1, int lenght2){
  int i1=lenght1,i2=lenght2,i=lenght1+lenght2;
  while (i1>0 && i2>0) {
    if (l1[i1]<l2[i2]) {
      rendu[--i]=l2[i2];
      i1--;
    }else{
      rendu[--i]=l2[i2];
      i2--;
    }
  }
  if (i1>0) {
    while (i1) {
      rendu[--i]=l1[i1];
      i1--;
    }
  }else{
    while(i2){
      rendu[--i]=l2[i2];
      i2--;
    }
  }
  return rendu;
}

void * mergesort(int *a){
  static int rendu[100];
}

int main (){
   int *a;
   a=gen();
   return 0;
}
