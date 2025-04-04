#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int value;
    struct cel *next;
} celula;

celula *createListFromArray(celula **list, int x[]) {
  celula *newElement = malloc(sizeof(celula)); // allocate memory for the new element
  newElement -> value = x[0];
  newElement -> next = NULL;
  *list = newElement; // saving list's first element
  celula *lastCreated = newElement; // helper variable

  int i;
  for (i = 1; i < 5; i++) {
      newElement = malloc(sizeof(celula));
      newElement -> value = x[i];
      newElement -> next = NULL;
      lastCreated -> next = newElement;
      lastCreated = newElement; // keeping track of the last element
  }

  return lastCreated; // the last element created might be the end of the queue
}

void printCelula(celula *list) { // prints all elements
    if (list == NULL) return;
    printf("%i\n", list -> value);
    printCelula(list -> next);
}

void addElement(celula *end, int x) { // add element at the beginning
  celula *new = malloc(sizeof(celula));
  end -> next = new;
  new -> value = x;
  new -> next = NULL;
}

int removeElement(celula **list) {
  celula *lixo = *list;
  int x = lixo -> value;
  *list = lixo -> next;
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