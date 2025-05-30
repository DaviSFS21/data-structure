#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cel {
  char text[10];
  struct cel *esq;
  struct cel *dir;
} no;

void printTree(no *bt) {
  if (bt != NULL) {
    if (bt -> esq != NULL) {
      printTree(bt -> esq);
    }
    printf("%s\n", bt -> text);
    if (bt -> dir != NULL) {
      printTree(bt -> dir);
    }
  }
}

void insertTree(no **bt, char x[]) {
  no *new = malloc(sizeof(no));
  strcpy(new -> text, x);
  new -> esq = NULL;
  new -> dir = NULL;
  if (*bt == NULL) {
    *bt = new;
    return;
  }
  if (x[0] < (*bt) -> text[0]) insertTree(&(*bt) -> esq, x);
  if (x[0] > (*bt) -> text[0]) insertTree(&(*bt) -> dir, x);
}

void removeTree(no **bt) {
  char rm[10];

  strcpy(rm, (*bt) -> text);
  printf("removed: %s\n", rm);

  if ((*bt) -> esq == NULL && (*bt) -> dir == NULL) {
    free(*bt);
    return;
  }
  
  if ((*bt) -> esq == NULL) {
    *bt = (*bt) -> dir;
    return;
  }
  
  if ((*bt) -> dir == NULL) {
    *bt = (*bt) -> esq;
    return;
  }

  no **next = &((*bt) -> dir);

  while (1) {
    if ((*next) -> esq == NULL) {
      strcpy((*bt) -> text, (*next) -> text);
      (*next) = (*next) -> dir;
      return;
    } else {
      next = &((*next) -> esq);
    }
  }
}

int main() {
  // TODO: initialize the pointer correctly
  no *tree = NULL;

  insertTree(&tree, "joao");
  insertTree(&tree, "davi");
  insertTree(&tree, "ana");
  insertTree(&tree, "poli");
  insertTree(&tree, "tiago");
  printTree(tree);
  removeTree(&tree);
  
  printTree(tree);

  return 0;
}