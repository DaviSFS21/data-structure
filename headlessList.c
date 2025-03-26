#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *prox;
} celula;

celula *createListFromArray(int x[]) {
  celula *newElement = malloc(sizeof(celula)); // allocate memory for the new element
  newElement -> valor = x[0];
  newElement -> prox = NULL;
  celula *list = newElement; // saving list's first element
  celula *lastCreated = newElement; // helper variable

  int i;
  for (i = 1; i < 5; i++) {
      newElement = malloc(sizeof(celula));
      newElement -> valor = x[i];
      newElement -> prox = NULL;
      lastCreated -> prox = newElement;
      lastCreated = newElement; // keeping track of the last element
  }

  return list;
}

void printCelula(celula *list) { // prints all elements
    if (list == NULL) return;
    printf("%i\n", list -> valor);
    printCelula(list -> prox);
}

void addElementAtStart(celula **list, int x) { // add element at the beginning
  celula *nova = malloc(sizeof(celula));
  nova -> prox = *list;
  nova -> valor = x;
  *list = nova;
}

void addElement(celula *p, int x) { // add element after the given address
  celula *nova = malloc(sizeof(celula));
  nova -> prox = p -> prox;
  nova -> valor = x;
  p -> prox = nova;
}

int removeElementAtStart(celula **list) {
  celula *lixo = *list;
  int x = lixo -> valor;
  *list = lixo -> prox;
  free(lixo);
  return x;
}

int removeElement(celula *p) { // remove the element after the given address
  if(!(p -> prox == NULL)) {
    celula *lixo = p -> prox;
    int x = lixo -> valor;
    p -> prox = lixo -> prox;
    free(lixo);
    return x;
  } else {
    return -999;
  }
}

celula *getElement(celula *list, int pos) { // get a random cel for operations
  celula *current = list;
  for(int i = 0; i < pos; i++) {
    current = current -> prox;
  }
  return current;
}

int main() {
  int intArray[] = {1,2,3,4,5};
  celula *list = createListFromArray(intArray);  
  
  addElementAtStart(&list,0);
  addElement(getElement(list,4),7);
  printCelula(list);
  printf("\n-------------------------------------------\n");
  printf("Removed at start: %i", removeElementAtStart(&list));
  printf("\n-------------------------------------------\n");
  printCelula(list);
  printf("\n-------------------------------------------\n");
  printf("Removed element: %i", removeElement(getElement(list,5)));
  printf("\n-------------------------------------------\n");
  printCelula(list);

  return 0;
}