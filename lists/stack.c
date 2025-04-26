#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int value;
    struct cel *next;
} celula;

void printCelula(celula *list) { // prints all elements
  if (list == NULL) {
    printf("\n");
    return;
  }
  printf("%i, ", list -> value);
  printCelula(list -> next);
}

void addElement(celula *list, int x) { // add element after the given address
  celula *new = malloc(sizeof(celula));
  new -> next = list -> next;
  new -> value = x;
  list -> next = new;
}

int removeElement(celula *list) { // remove the element after the given address
  if(list -> next == NULL) return -9999;
  celula *lixo = list -> next;
  int x = lixo -> value;
  list -> next = lixo -> next;
  free(lixo);
  return x;
}

int main() {
  int intArray[] = {1,2,3,4,5};
  celula *list = malloc(sizeof(celula));
  list -> next = NULL;
  
  for(int i = 0; i < 5; i++) {
    addElement(list, intArray[i]);
  }

  printCelula(list -> next);
  printf("\n-------------------------------------------\n");
  addElement(list, 6);
  printf("List with added element: 6\n");
  printCelula(list -> next);
  printf("-------------------------------------------\n");
  addElement(list, 7);
  printf("List with added element: 7\n");
  printCelula(list -> next);
  printf("-------------------------------------------\n");
  printf("Removed: %i\n", removeElement(list));
  printCelula(list -> next);
  printf("-------------------------------------------\n");
  printf("Removed: %i\n", removeElement(list));
  printCelula(list -> next);
  printf("-------------------------------------------\n");
  printf("Removed: %i\n", removeElement(list));
  printCelula(list -> next);
  printf("-------------------------------------------\n");

  return 0;
}
