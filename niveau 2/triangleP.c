#include <stdio.h>
#include <stdlib.h>
#define nbetages 25
void printls(int num[], int size){
  for (size_t i = 0; i < size; i++) {
    printf("%d\t",num[i] );
  }
  printf("\n");
}

int trianglePascal(int nb){
  static int a[nbetages]={1};
  static int b[nbetages];
  for (int i = 1; i < nb; i++) {
    for (int j = 1; j < i-1 ; j++) {
      b[j]=a[j-1]+a[j];
    }
    b[0]=1;
    b[i-1]=1;
    for(int j = 0; j < i; j++) a[j]=b[j]; // le C c'est sorcier des fois
    printf("n%i :",i);
    printls(a,i);
  }
}

int main() {
  printf("Triangle de Pascal pour %i étages:\n",nbetages );
  trianglePascal(nbetages);
  return 0;
}
