#include <stdio.h>
#include <stdlib.h>
#define size malloc(sizeof(node))

typedef struct node {
    int v;
    struct node * g;
    struct node * d;
} node;

void generate( node * r, int * list,int deb, int fin){
    int mid=(int) (fin-deb)/2;
    int len=(fin-deb+1);
    r->v = list[deb+mid];
    r->g=(node*)size;
    r->d=(node*)size;

    if(len>3){
      generate(r->g,list,deb,mid-1);
      generate(r->d,list,mid+1,fin);
    }else if(len==3){
      r->g->v=list[deb+0];
      r->d->v=list[deb+2];
    }else if(len==2){
      r->g->v=list[deb];
    }else{
      printf("Liste trop courte : %i\n",len);
    }
}
void add(node *r, int v){
  if (r->v > v) {
    if(r->d){
      add(r->d,v);
    }else{
      r->d=(node*) size;
      r->d->v=v;
    }
  }else{
    if(r->g){
      add(r->g,v);
    }else{
      r->g=(node*) size;
      r->g->v=v;
    }
  }
}

int check(node *r){
  int g=1,d=1;
    if(r->g){
      if(r->g->v < r->v){
        g=check(r->g);
      }
    }
    if(r->d){
      if(r->d->v > r->v){
        g=check(r->d);
      }
    }
    return g&&d;
}

void print(node *r,int tabs,char side){
    for(int i=0;i<tabs-1;i++)printf("---|");
    if(tabs)printf("--%c|", side);
    printf("%i\n",r->v);
    if(r->d!=0){
        print(r->d,tabs+1,'d');
    }
    if(r->g!=0){
        print(r->g,tabs+1,'g');
    }
}

int main() {
    node * b = (node *) size;
    static int elems[]={1*2,2*2,3*2,4*2,5*2,6*2,7*2};
    generate(b,elems,0,6);
    printf("Iel est bien : %i\n",check(b));
    print(b,0,0);
    add(b,3);
    print(b,0,0);
    printf("Iel est bien : %i\n",check(b));
    return 0;
}
