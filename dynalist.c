#include <stdio.h>
#include <stdlib.h>
/*struct node{
  int value;
  int *next;
};

void add(struct node l, int value){
  while (l.next!=0) {
    struct node next;
    next=*l.next;
  }
  struct node new;
  new.value = value;
  l.next = new;
}*/

typedef struct Node {
    int v;
    struct Node * n; // Très bizarre
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
  node * l = 0;
  l = (node *) malloc(sizeof(node));
  l->v = 1;
  l->n = 0;
  add(l,5);
  printls(l);
  printf("Après un add: \n");
  add(l,69);
  printls(l);
  return 0;
}
