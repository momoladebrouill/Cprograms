#include <stdio.h>

struct imlex{
  float re;
  float im;
};

struct imlex mul(struct imlex a,struct imlex b){
  struct imlex r;
  r.re=a.re*b.re-a.im*b.im;
  r.im=a.re*b.im+a.im*b.re;
  return r;
}

struct imlex add(struct imlex a, struct imlex b){
  struct imlex r;
  r.re=a.re+b.re;
  r.im=a.im+b.im;
  return r;
}

int squMod(struct imlex z){
  return z.re*z.re+z.im*z.im;
}
void mandelbrot(int iter,int sizex,int sizey) {
  int i;
  static char degrade[]=" .:-=+*#%@";
  struct imlex z;
  struct imlex c;
  for (size_t x = 0; x < sizex; x++) {
    for (size_t y = 0; y < sizey; y++) {
      z.im=0;
      z.re=0;
      c.re=3.5*x/(sizex-1)-2.5;
      c.im=-2.5*y/(sizey-1)+1.25;
      i=0;
      while (i<iter && squMod(z) < 4) {
        i++;
        z=add(mul(z,z),c);
      }
      printf("%c",degrade[(int)((float)i/iter*9)]);
    }
    printf("\n");
  }
}
int poW(int base,int exp){
  int r=1;
  for (size_t i = 0; i < exp; i++) {
    r*=base;
  }
  return r;
}
int parseInt(const char *num,int len){
  int result=0;
  int ischar=1;
  int current;
  int puis=1;
  for(int i=len;i>0;i--){
    current=69;
    for (int n = 48; n < 58; n++) {
      if (n==num[i-1]) {
        current=n-48;
        n=69; // On a trouvé qui c'était, on sort
      }
    }
    if (current==69) {
      //printf("Not a Number (on fait pas du JS non plus)\n");
      //i=-1; // On a pas trouvé, ce n'est pas un chiffre, on sort :(
    }else{
      result+=current*puis;
      puis*=10;
    }
  }
  return result;
}
int main(int argc, char const *argv[]) {
  int precision;
  if(argc>1){
    precision=parseInt(argv[1],sizeof(argv[1])/sizeof(argv[1][0]));
  }
  mandelbrot(precision,50,50);
  return 0;
}
