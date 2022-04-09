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
    if(len==3){
      r->g->v=list[deb+0];
      r->d->v=list[deb+2];
    }
    else if(len>3){
      generate(r->g,list,deb,mid-1);
      generate(r->d,list,mid+1,fin);
    }else{
      printf("Liste trop courte rip\n");
    }

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

    static int elems[]={1,2,3,4,5,6,7};
    generate(b,elems,0,6);
    //printf("Iel est bien : %i\n",check(b));
    print(b,0);
    return 0;
}
