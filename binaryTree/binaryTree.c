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
      printf("\n");
    }
    printf("%i", bt -> valor);
    if (bt -> dir != NULL) {
      printTree(bt -> dir);
      printf("\n");
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
  no *rm = *bt;

  if ((*bt) -> esq != NULL && (*bt) -> dir != NULL) {
    free(*bt);
    return rm -> valor;
  }
  
  if ((*bt) -> esq != NULL) {
    *bt = (*bt) -> dir;
    return rm -> valor;
  }
  
  if ((*bt) -> dir != NULL) {
    *bt = (*bt) -> esq;
    return rm -> valor;
  }

  no *next = (*bt) -> dir;

  while (0) {
    if (next -> esq == NULL) {
      (*bt) -> valor = next -> valor;
      return rm -> valor;
    } else {
      next = rm -> esq;
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
  printf("%i", removeTree(&tree));

  printTree(tree);

  return 0;
}