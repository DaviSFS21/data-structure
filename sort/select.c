#include<stdio.h>

void printArray(int n, int v[]) {
  for(int i = 0; i < n; i++) {
    printf("%i) %ikm/h\n", i + 1, v[i]);
  }
}

void selectSort(int n, int v[]) {
  for (int i = 0; i < n; i++) {
    int greater = v[i];
    int greaterPos = i;
    for (int j = i + 1; j < n; j++) {
      if (v[j] > greater) {
        greater = v[j];
        greaterPos = j;
      }
    }
    int x = v[i];
    v[i] = greater;
    v[greaterPos] = x;
  }
}

int main() {
  int v[] = {331,326,333,330,329,319,325};
  int vSize = sizeof(v) / sizeof(v[0]);
  selectSort(vSize, v);

  printArray(vSize, v);

  return 0;
}