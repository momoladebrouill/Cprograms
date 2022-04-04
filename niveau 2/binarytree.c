#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size malloc(sizeof(node))

typedef struct node {
    int v;
    struct node * g;
    struct node * d;
} node;



node * generate(node * r, int val){
    r->v=val;
    int vg=val-2,vd=val-1;

    if (vg>0){
      r->g=(node*) size;
      generate(r->g,vg);
    }else{r->g=0;} //maybe use less

    if (vd>0){
      r->d=(node*) size;
      generate(r->d,vd);
    }else{r->d=0;} // so this does

    return r;
}

int check(node *r){
    if(r->g == 0 || r->d == 0){
        return 1;
    }
    if((r->g->v < r->v) && (r->v < r->d->v) ){
      return check(r->g) && check(r->d);
    }
    return 0;
}

void print(node *r,int tabs){
    for(int i=0;i<tabs;i++)printf("---|");
    printf("%i\n",r->v);
    if(r->d!=0 && r->g!=0){
        print(r->d,tabs+1);
        print(r->g,tabs+1);
    }
}

int main() {
    srand(time(NULL));

    node * b = (node *) size;
    generate(b,5);
    printf("%i\n",check(b));
    print(b,0);
    return 0;
}
