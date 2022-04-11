#include <stdio.h>
#include <stdlib.h>
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

void mandelbrot(int iter,int sizex,int sizey) {
  int i;
  struct imlex z;
  struct imlex c;
  for (size_t x = 0; x < sizex; x++) {
    for (size_t y = 0; y < sizey; y++) {
      z.im=0;
      z.re=0;
      c.re=3.5*x/(sizex-1)-2.5;
      c.im=-2.5*y/(sizey-1)+1.25;
      int i=0;
      while (i<iter && z.re*z.re+z.im*z.im < 4) {
        i++;
        z=add(mul(z,z),c);
      }
      printf("%c",i/iter>.5 ? '*' : ' ');
    }
    printf("\n");
  }
}

int main(){
  printf("yaay\n");
  mandelbrot(500,50,50);
}
