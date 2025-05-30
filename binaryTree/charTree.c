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

  int i = 0;

  while (x[i] == (*bt) -> text[0] && i < 3) i++;

  if (x[i] < (*bt) -> text[i]) insertTree(&(*bt) -> esq, x);
  if (x[i] > (*bt) -> text[i]) insertTree(&(*bt) -> dir, x);
}

void removeTree(no **bt) {
  printf("removed: %s\n", (*bt) -> text);

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

  no **dad = &((*bt) -> dir);
  no **son = &((*dad) -> esq);
  if ((*son) != NULL) *son = (*dad) -> esq;
  else {
    (*dad) -> esq = (*bt) -> esq;
    *bt = *dad;
    return;
  }

  do {
    dad = son;
    son = &((*son) -> esq);
  } while((*son) -> esq != NULL);

  (*dad) -> esq = (*son) -> dir;
  (*son) -> esq = (*bt) -> esq;
  (*son) -> dir = (*bt) -> dir;
  free(*bt);
}

int main() {
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