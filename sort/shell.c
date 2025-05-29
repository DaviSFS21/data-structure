#include<stdio.h>

void printArray(int n, int v[]) {
  for(int i = 0; i < n; i++) {
    printf("%i) %ikm/h\n", i + 1, v[i]);
  }
}

void shellSort(int v[], int n) {
  for (int gap = n/2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int x = v[i];
      int j;
      for (j = i; j >= gap && v[j - gap] > x; j -= gap) {
        v[j] = v[j - gap];
      }
      v[j] = x;
    }
  }
}

int main() {
  int array[] = {331,326,333,330,329,319,325};
  int arraySize = sizeof(array) / sizeof(array[0]);
  shellSort(array, arraySize);

  printArray(arraySize, array);

  return 0;
}
