#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *prox;
} celula;

celula *createListFromArray(int x[]) { // headed lists allows us to treat every cell with a same treatment
  celula *newElement = malloc(sizeof(celula)); // allocate memory for the new element
  newElement -> valor = 0;
  newElement -> prox = NULL;
  celula *list = newElement; // saving list's first element
  celula *lastCreated = newElement; // helper variable

  int i;
  for (i = 0; i < 5; i++) {
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

void addElement(celula *p, int x) { // add element after the given address
  celula *nova = malloc(sizeof(celula));
  nova -> prox = p -> prox;
  nova -> valor = x;
  p -> prox = nova;
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
  pos++;
  celula *current = list;
  for(int i = 1; i < pos; i++) {
    current = current -> prox;
  }
  return current;
}

int main() {
  int intArray[] = {1,2,3,4,5};
  celula *list = createListFromArray(intArray);  
  
  addElement(list,0);
  printCelula(list -> prox);
  printf("\n-------------------------------------------\n");
  printf("Removed element: %i", removeElement(list));
  printf("\n-------------------------------------------\n");
  printf("Removed element: %i", removeElement(list));
  printf("\n-------------------------------------------\n");
  printCelula(list -> prox);

  return 0;
}