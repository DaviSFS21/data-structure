#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int value;
    struct cel *next;
} celula;

celula *createListFromArray(int x[]) { // headed lists allows us to treat every cell with a same treatment
  celula *newElement = malloc(sizeof(celula)); // allocate memory for the new element
  newElement -> value = 0;
  newElement -> next = NULL;
  celula *list = newElement; // saving list's first element
  celula *lastCreated = newElement; // helper variable

  int i;
  for (i = 0; i < 5; i++) {
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

void addElement(celula *p, int x) { // add element after the given address
  celula *new = malloc(sizeof(celula));
  new -> next = p -> next;
  new -> value = x;
  p -> next = new;
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
  pos++;
  celula *current = list;
  for(int i = 1; i < pos; i++) {
    current = current -> next;
  }
  return current;
}

int main() {
  int intArray[] = {1,2,3,4,5};
  celula *list = createListFromArray(intArray);  
  
  addElement(getElement(list,0),7);
  addElement(getElement(list,3),8);
  printCelula(list -> next);
  printf("\n-------------------------------------------\n");
  printf("Removed element: %i", removeElement(getElement(list,0)));
  printf("\n-------------------------------------------\n");
  printf("Removed element: %i", removeElement(getElement(list,5)));
  printf("\n-------------------------------------------\n");
  printCelula(list -> next);

  return 0;
}
