#include <stdio.h>

#define size malloc(sizeof(node))

typedef struct node {
    int v;
    struct node * g;
    struct node * d;
} node;

static int l1,l2;
node * generate( node * r, int * list, int len){
    l1=(int) len/2+len%2;
    l2=(int) len/2;
    
    r->v = &(list);
    if(l1>0){
        r->g = (node * ) size;
        generate(r->g,list,l1-1);
    }
    
    if(l2>0){
        r->d = (node*) size;
        generate(r->d,*(list+l1),l2-1);
    }
    
    /*if(l2){
        r->d = (node*) size;
        int *deb=(val+l1);
        generate(r->d,deb,l2);
    }*/
    
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
    if(r->d!=0){
        print(r->d,tabs+1);
    }
    if(r->g!=0){
        print(r->g,tabs+1);
    }
}

int main() {
    node * b = (node *) size;
    /*b->g=(node*)size;
    b->d=(node*)size;
    b->g->v=1;
    b->d->v=3;
    b->v=2;
    b->g->g=(node*)size;
    b->g->g->v=5;*/
    static int elems={1,2,3,4,5,6,7,8};
    generate(b,elems,5);
    printf("Iel est bien : %i\n",check(b));
    print(b,0);
    return 0;
}
