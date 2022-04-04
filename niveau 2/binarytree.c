#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size malloc(sizeof(node))

typedef struct node { 
    int v;
    struct node * g;
    struct node * d;
} node;

node * generate(node * r, int val,int * done){
    for(size_t i;i<5;i++){}
    if(val>0){
        r->v=val;
        int vg=rand()%val,vd=rand()%val*2;
        r->g=(node*)size;
        r->d=(node*)size;
        generate(r->g,val-2,done);
        generate(r->d,val-1,done);
    }else{
        r->v=-1;
    }
    return r;
}

int check(node *r){
    if(r->g == 0 && r->d == 0){
        return 1;
    }else if((r->g->v < r->v) && (r->g->v < r->d->v)){
        return check(r->g) && check(r->d);
    }else{
        return 0;
    }
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
    node * a = (node *) size;
    a->v=5;
    node *b=(node*)size;

    int done[5]; 
    generate(b,5,*done);

    printf("%i\n---\n",check(b));
    print(b,0);
    return 0;
}
