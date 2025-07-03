#include<stdio.h>
#include<math.h>

void printArray(int n, int v[]) {
  for(int i = 0; i < n; i++) {
    printf("%i) %ikm/h\n", i + 1, v[i]);
  }
}

int generateHibbardGaps(int n, int gaps[]) {
  int i = 0;
  while ((1 << (i + 1)) - 1 < n) {
    gaps[i++] = (1 << (i + 1)) - 1;
  }
  return i;
}

void shellSort(int v[], int n, int gaps[], int gapsSize) {
  for (int i = gapsSize - 1; i >= 0; i--) {
    for (int j = 0; j + gaps[i] < n; j++) {
      for (int k = j; v[k] < v[k + gaps[i]] && k > 0; k--) {
        int x = v[k];
        v[k] = v[k + gaps[i]];
        v[k + gaps[i]] = x;
      }
    }
  }
}

int main() {
  int array[] = {331,326,333,330,329,319,325,308,324,310};

  int gaps[32];
  int arraySize = sizeof(array) / sizeof(array[0]);
  int gapsSize = generateHibbardGaps(arraySize, gaps);
  shellSort(array, arraySize, gaps, gapsSize);

  printArray(arraySize, array);

  return 0;
}
