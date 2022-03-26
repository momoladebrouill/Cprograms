#include <stdio.h>
#include <stdlib.h>

int calculateSum(int num[],int size);
void printls(int num[],size_t size);
int trianglePascal(int nb);

int main() {
  trianglePascal(10);
  return 0;
}

void printls(int num[], size_t size){
  for (size_t i = 0; i < size; i++) {
    printf("%d\t",num[i] );
  }
  printf("\n");
}

int trianglePascal(int nb){
  int s[]={1};
  for (int i = 1; i < nb; i++) {
    int next[i+1];
    next[0]=1;
    next[i]=1;

    for (int j = 1; j < i-1 ; j++) {
      next[j]=0;
    }

    int s[i+1];
    for(int j = 0; j < i ; j++){
      s[j]=next[j];
    }
    printls(s,i);
  }
}
