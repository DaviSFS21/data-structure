#include<stdio.h>

void printArray(int n, int v[]) {
  for(int i = 0; i < n; i++) {
    printf("%i) %ikm/h\n", i + 1, v[i]);
  }
}

void shellSort(int v[], int n) {
  for (int gap = n/2; gap > 0; gap /= 2)
    for (int i = 0; v[i + 1] > v[i] && i > 0; i++) {
      int x = v[i - 1];
      v[i - 1] = v[i];
      v[i] = x;
    }
}

int main() {
  int v[] = {331,326,333,330,329,319,325};
  int vSize = sizeof(v) / sizeof(v[0]);
  shellSort(v, vSize);

  printArray(vSize, v);

  return 0;
}
