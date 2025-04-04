#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int value;
    struct cel *next;
} celula;

void printCelula(celula *start) { // prints all elements
    if (start == NULL) {
      printf("\n");
      return;
    }
    printf("%i, ", start -> value);
    printCelula(start -> next);
}

void addElement(celula **start, celula **end, int x) { // add element at the beginning
  celula *new = malloc(sizeof(celula));
  new -> value = x;
  new -> next = NULL;

  if(*start == NULL && *end == NULL) { // if there are no elements, both start and end will point to new
    *start = new;
    *end = new;
  } else { // or else, the penultimate element will point to new, then the end will point to new too
    (*end) -> next = new;
    *end = new;
  }
}

int removeElement(celula **start, celula **end) {
  if(*start == NULL && *end == NULL) return -9999;
  else {
    celula *del = *start; // del var stores the first cell
    int x = del -> value;
    *start = del -> next;
    if (del -> next == NULL) { // if there is only one element, both list adresses will be NULL
      *end = NULL;
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
  printf("List with added element: 6\n");
  printCelula(listStart);
  printf("-------------------------------------------\n");
  addElement(&listStart, &listEnd, 7);
  printf("List with added element: 7\n");
  printCelula(listStart);
  printf("-------------------------------------------\n");
  printf("Removed: %i\n", removeElement(&listStart, &listEnd));
  printCelula(listStart);
  printf("-------------------------------------------\n");
  printf("Removed: %i\n", removeElement(&listStart, &listEnd));
  printCelula(listStart);
  printf("-------------------------------------------\n");
  printf("Removed: %i\n", removeElement(&listStart, &listEnd));
  printCelula(listStart);
  printf("-------------------------------------------\n");

  return 0;
}