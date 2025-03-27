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

celula *getLastCelula(celula *list) { // prints all elements
  if (list == NULL) return;
  if (list -> prox == NULL) return list;
  getLastCelula(list -> prox);
}

void printCelula(celula *list) { // prints all elements
    if (list == NULL) return;
    printf("%i\n", list -> valor);
    printCelula(list -> prox);
}

void addElement(celula **list, int x) { // add element at the beginning
  celula *nova = malloc(sizeof(celula));
  nova -> prox = *list;
  nova -> valor = x;
  *list = nova;
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
  celula *list = createListFromArray(intArray);
  // to track the last element, we could return the address
  // of the celula with a NULL prox pointer, after giving
  // the createListFromArray the intArray and the
  // *list too.
  // createListFromArray(celula *listStart, int x[])
  
  printCelula(list);
  printf("\n-------------------------------------------\n");
  addElement(&list,6);
  printf("List with added element: \n");
  printCelula(list);
  printf("\n-------------------------------------------\n");
  printf("Removed at start: %i", removeElement(&list));
  printf("\n-------------------------------------------\n");
  printCelula(list);
  printf("\n-------------------------------------------\n");

  return 0;
}