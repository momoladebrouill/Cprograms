#include <stdio.h>
#include <math.h>

const char vide[2]="_";
char tabl[64];

void setat(int x, int y, char val){
  tabl[x+y*8]=val;
}

char getat(int x,int y){
  return tabl[x+y*8];
}

int visualize(){
  printf("\n");
  for (int i = 0; i < 8; i++) {
    printf("\t");
    for (int j = 0; j < 8; j++) {
      printf("%c ",getat(i,j));
    }
    printf("\n");
  }
  printf("\n");
  return 0;
};

int putatcolumn(int col,char *val){
  int where=7;
  while(getat(where,col)!=*vide && where>=0){
    where--;
  }
  setat(where,col,*val);
}
int main() {
  printf("\n=== Execution del code ===\n");
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      setat(i,j,*vide);
    }
  }
  int a=0;
  char val[2]= "t";
  while (a>=0) {
    visualize();
    printf("Un char stp boto : ");
    scanf("%2s", val);
    printf("Un lieu stp bata : ");
    scanf("%2d",&a);
    putatcolumn(a,val);


  }
  return 0;
}
