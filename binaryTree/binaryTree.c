#include<stdio.h>
#include<stdlib.h>

typedef struct cel {
  int valor;
  struct cel *esq;
  struct cel *dir;
} no;

void printTree(no *bt) {
  if (bt != NULL) {
    if (bt -> esq != NULL) {
      printTree(bt -> esq);
    }
    printf("%i\n", bt -> valor);
    if (bt -> dir != NULL) {
      printTree(bt -> dir);
    }
  }
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

int removeTree(no **bt) {
  int rm = (*bt) -> valor;

  if ((*bt) -> esq == NULL && (*bt) -> dir == NULL) {
    free(*bt);
    return rm;
  }
  
  if ((*bt) -> esq == NULL) {
    *bt = (*bt) -> dir;
    return rm;
  }
  
  if ((*bt) -> dir == NULL) {
    *bt = (*bt) -> esq;
    return rm;
  }

  no **next = &((*bt) -> dir);

  while (1) {
    if ((*next) -> esq == NULL) {
      (*bt) -> valor = (*next) -> valor;
      (*next) = (*next) -> dir;
      return rm;
    } else {
      next = &((*next) -> esq);
    }
  }

  return 0;
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
  printf("\nremove: %i\n\n", removeTree(&tree));
  
  printTree(tree);

  return 0;
}