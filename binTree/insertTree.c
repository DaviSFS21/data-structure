#include<stdio.h>
#include<stdlib.h>

typedef struct cel {
  int valor;
  struct cel *esq;
  struct cel *dir;
} no;

void printTree(no *bt) {
  if (bt -> esq != NULL)
    printTree(bt -> esq);
  printf("%i", bt -> valor);
  if (bt -> esq != NULL)
    printTree(bt -> dir);
}

void insertTree(no **bt, int x) {
  no *new = malloc(sizeof(no));
  new -> valor = x;
  new -> esq = NULL;
  new -> dir = NULL;
  if (*bt == NULL) {
    *bt = new;
    return;
  }
  if (x < (*bt) -> valor) insertTree(&(*bt) -> esq, x);
  if (x > (*bt) -> valor) insertTree(&(*bt) -> dir, x);
}

int main() {
  // TODO: initialize the pointer correctly
  no *tree = NULL;

  insertTree(&tree, 4);
  insertTree(&tree, 2);
  insertTree(&tree, 10);
  insertTree(&tree, 5);
  insertTree(&tree, 7);

  printTree(tree);

  return 0;
}