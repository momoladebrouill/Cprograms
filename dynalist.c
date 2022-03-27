#include <stdio.h>
#include <stdlib.h>

typedef struct node { //on définit un nouveau type, qui est une structure nommé node
    int v;
    struct node * n; // Très bizarre
} node;

void printls(node * h) {
    node * c = h;
    while (c != 0) {
        printf("%d\n", c->v);
        c = c->n;
    }
}

void add(node * h, int v){
  node * c = h;
  while (c->n != 0) {
    c = c->n;
  }
  c->n = (node *) malloc(sizeof(node));
  c = c->n;
  c->v = v;
  c->n = 0;
}

int main(){
  node * l = (node *) malloc(sizeof(node));
  l->v = 1,l->n = 0;
  add(l,5);
  add(l,69);
  for (size_t i = 0; i < 10; i++) {
    add(l,i);
  }
  printls(l);
  return 0;
}
