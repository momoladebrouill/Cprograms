#include <stdio.h>
#include <math.h>

char tabl[64];
int tour=0;
const char val[4]= "XO_";

void setat(int x, int y, int tour){
  tabl[x+y*8]=val[tour];
}

char getat(int x,int y){
  return tabl[x+y*8];
}

int visualize(){
  printf("\t  0 1 2 3 4 5 6 7\n");
  for (int i = 0; i < 8; i++) {
    printf("\t |");
    for (int j = 0; j < 8; j++) {
      printf("%c ",getat(i,j));
    }
    printf("|\n");
  }
  printf("\n");
  return 0;
};

int putatcolumn(int col,int tour){
  int where=7;
  while(getat(where,col)!=val[3] && where>=0){
    where--;
  }
  setat(where,col,tour);
}
int main() {
  printf("\n=== Execution del code ===\n");
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      setat(i,j,3);
    }
  }
  int lieu=0;


  while (lieu>=0) {
    visualize();
    printf("Un lieu stp bata : ");
    scanf("%2d",&lieu);
    tour=(tour+1)%2;
    putatcolumn(lieu,tour);


  }
  return 0;
}
