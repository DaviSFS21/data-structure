#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *prox;
} celula;

celula *createListFromArray(celula **list, int x[]) {
  celula *newElement = malloc(sizeof(celula)); // allocate memory for the new element
  newElement -> valor = x[0];
  newElement -> prox = NULL;
  *list = newElement; // saving list's first element
  celula *lastCreated = newElement; // helper variable

  int i;
  for (i = 1; i < 5; i++) {
      newElement = malloc(sizeof(celula));
      newElement -> valor = x[i];
      newElement -> prox = NULL;
      lastCreated -> prox = newElement;
      lastCreated = newElement; // keeping track of the last element
  }

  return lastCreated; // the last element created might be the end of the queue
}

void printCelula(celula *list) { // prints all elements
    if (list == NULL) return;
    printf("%i\n", list -> valor);
    printCelula(list -> prox);
}

void addElement(celula *end, int x) { // add element at the beginning
  celula *nova = malloc(sizeof(celula));
  end -> prox = nova;
  nova -> valor = x;
  nova -> prox = NULL;
}

int removeElement(celula **list) {
  celula *lixo = *list;
  int x = lixo -> valor;
  *list = lixo -> prox;
  free(lixo);
  return x;
}

int main() {
  int intArray[] = {1,2,3,4,5};
  celula *listStart;
  celula *listEnd = createListFromArray(&listStart, intArray);
  
  printCelula(listStart);
  printf("\n-------------------------------------------\n");
  addElement(listEnd,6);
  printf("List with added element: \n");
  printCelula(listStart);
  printf("\n-------------------------------------------\n");
  printf("Removed at start: %i", removeElement(&listStart));
  printf("\n-------------------------------------------\n");
  printCelula(listStart);
  printf("\n-------------------------------------------\n");

  return 0;
}