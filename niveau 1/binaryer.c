#include <stdio.h>
#include <stdlib.h>

char * binprint(int num,char * p,int l){
  int t=1;
  int ind=0;
  while (ind<l){
    p[ind] = t&num ? '1':'0';
    t = t<<1;
    ind++;
  }
  //Renverser la liste
  for(size_t i=0;i<(int)ind/2;i++){
    p[i] = p[i]^p[ind-1-i];
    p[ind-1-i] = p[i]^p[ind-1-i];
    p[i] = p[i]^p[ind-1-i];
  }
  return p;
}

int main(int argc, char const *argv[]) {
  char s[100];
  int a=0b0011;
  int b=0b0101;
  binprint(a,s,4);
  printf("a: %s\n",s);
  binprint(b,s,4);
  printf("b: %s\n",s);
  binprint((a|b)&~(a&b),s,4);
  printf("(a|b)&~(a&b): %s\n",s);
  binprint(a^b,s,4);
  printf("a^b: %s\n",s);
  return 0;
}
