#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int value;
    struct cel *next;
} celula;

void printCelula(celula *start) { // prints all elements
    if (start == NULL) return;
    printf("%i\n", start -> value);
    printCelula(start -> next);
}

void addElement(celula **start, celula **end, int x) { // add element at the beginning
  celula *new = malloc(sizeof(celula));
  new -> value = x;
  new -> next = NULL;

  if(*start == NULL && *end == NULL) {
    *start = new;
    *end = new;
  } else {
    (*end) -> next = new;
    *end = new;
  }
}

int removeElement(celula **start, celula **end) {
  if(*start == NULL && *end == NULL) return -9999;
  else {
    celula *del = *start; // del var stores the first cell
    int x = del -> value;
    if (del -> next == NULL) { // if there is only one element, both list adresses will be NULL
      *start = NULL;
      *end = NULL;
    } else { // otherwise, start will get the element after the deleted element
      *start = del -> next;
    }
    free(del);
    return x;
  }
}

int main() {
  int intArray[] = {1,2,3,4,5};
  celula *listStart = NULL;
  celula *listEnd = NULL;

  for(int i = 0; i < 5; i++) {
    addElement(&listStart, &listEnd, intArray[i]);
  }
  
  printCelula(listStart);
  printf("\n-------------------------------------------\n");
  addElement(&listStart, &listEnd, 6);
  printf("List with added element: \n");
  printCelula(listStart);
  printf("\n-------------------------------------------\n");
  printf("Removed at start: %i", removeElement(&listStart, &listEnd));
  printf("\n-------------------------------------------\n");
  printCelula(listStart);
  printf("\n-------------------------------------------\n");

  return 0;
}