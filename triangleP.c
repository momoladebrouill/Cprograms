#include <stdio.h>
#include <stdlib.h>

void printls(int num[], int size){
  for (size_t i = 0; i < size; i++) {
    printf("%d\t",num[i] );
  }
  printf("\n");
}

int trianglePascal(int nb){
  int a[100];
  int b[100];
  for (int i = 0; i < nb; i++) {
    a[0]=1;
    a[i]=1;
    b[0]=1;
    b[i]=1;
    for (int j = 1; j < i-1 ; j++) {
      b[j]=a[j-1]+a[j];
    }

    for(int j = 0; j < i +1; j++){
      a[j]=b[j];
    }
    printls(a,i);
  }
}

int main() {
  trianglePascal(10);
  return 0;
}
