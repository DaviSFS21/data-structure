#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int value;
    struct cel *next;
} celula;

celula *createListFromArray(int x[]) {
  celula *newElement = malloc(sizeof(celula)); // allocate memory for the new element
  newElement -> value = x[0];
  newElement -> next = NULL;
  celula *list = newElement; // saving list's first element
  celula *lastCreated = newElement; // helper variable

  int i;
  for (i = 1; i < 5; i++) {
      newElement = malloc(sizeof(celula));
      newElement -> value = x[i];
      newElement -> next = NULL;
      lastCreated -> next = newElement;
      lastCreated = newElement; // keeping track of the last element
  }

  return list;
}

void printCelula(celula *list) { // prints all elements
    if (list == NULL) return;
    printf("%i\n", list -> value);
    printCelula(list -> next);
}

void addElementAtStart(celula **list, int x) { // add element at the beginning
  celula *new = malloc(sizeof(celula));
  new -> next = *list;
  new -> value = x;
  *list = new;
}

void addElement(celula *p, int x) { // add element after the given address
  celula *new = malloc(sizeof(celula));
  new -> next = p -> next;
  new -> value = x;
  p -> next = new;
}

int removeElementAtStart(celula **list) {
  celula *lixo = *list;
  int x = lixo -> value;
  *list = lixo -> next;
  free(lixo);
  return x;
}

int removeElement(celula *p) { // remove the element after the given address
  if(!(p -> next == NULL)) {
    celula *lixo = p -> next;
    int x = lixo -> value;
    p -> next = lixo -> next;
    free(lixo);
    return x;
  } else {
    return -999;
  }
}

celula *getElement(celula *list, int pos) { // get a random cel for operations
  celula *current = list;
  for(int i = 0; i < pos; i++) {
    current = current -> next;
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