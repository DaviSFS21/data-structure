#include<stdio.h>

void printArray(int n, int v[]) {
  for(int i = 0; i < n; i++) {
    printf("%i) %ikm/h\n", i, v[i]);
  }
}

void insertSort(int n, int v[]) {
  for (int i = 1; i < n; i++) {
    for (int j = i; v[j - 1] < v[j] && j > 0; j--) {
      int x = v[j - 1];
      v[j - 1] = v[j];
      v[j] = x;
    }
  }
}

int main() {
  int v[] = {331,326,333,330,329,319,325};
  int vSize = sizeof(v) / sizeof(v[0]);
  insertSort(vSize, v);

  printArray(vSize, v);
}