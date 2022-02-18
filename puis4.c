#include <stdio.h>
#include <math.h>

char tabl[64];
int tour=0;
const int null=2;/*position du caractère null*/
const char val[4]="XO_";

void setat(int x, int y, int tour){
  tabl[x+y*8]=val[tour];
};

char getat(int x,int y){
  if(x>=0 && x<8 && y>=0 && y<8){
    return tabl[x+y*8];
  }
  return val[null];
};

int checkforpui(int x, int y){
  int i,som,xx,yy;
  for (int dx = -1; dx < 2; dx++) {
    for (int dy = -1; dy < 2; dy++) {
      i=1;
      while(getat(x,y)==getat(x+dx*i,y+dy*i) && i<5){
        i++;
      }
      som=0;
      xx=x+dx*i;
      yy=x+dy*i;
      for(int j=0; j<4;j++){
        som+=getat(xx,yy)==getat(xx-dx*j,yy-dy*j);
      }
      printf("Depuis (%d,%d) il y'a le même char %dfois\n",xx,yy,som );
      if (som==4) {
        return 1;
      }
    }
    return 0;
  }
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
  while(getat(where,col)!=val[null] && where>=0){
    where--;
  }
  setat(where,col,tour);
  printf("Il y'a un puissance 4: %d\n",checkforpui(where,col));
}

int main() {
  printf("\n=== Execution del code ===\n");
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      setat(i,j,null);
    }
  }
  int lieu=0;
  while (lieu>=0) {
    visualize();
    tour=(tour+1)%2;
    printf("Un lieu stp bata (%c) : ",val[tour]);
    scanf("%2d",&lieu);
    putatcolumn(lieu,tour);
  }
  return 0;
};
