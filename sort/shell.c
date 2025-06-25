#include<stdio.h>
#include<math.h>

void printArray(int n, int v[]) {
  for(int i = 0; i < n; i++) {
    printf("%i) %ikm/h\n", i + 1, v[i]);
  }
}

void shellSort(int v[], int n) {
  int max_gaps_size = 0;
  for (int i = 0; pow(2, i) + 1 < n; i++) {
      max_gaps_size++;
  }
  int gaps[max_gaps_size];

  gaps[0] = 1;

  for (int i = 1; pow(2, i) + 1 < n; i++) {
    gaps[i] = pow(2, i) + 1;
  }

  for (int i = max_gaps_size; i > 0; i--) {
    for (int j = 0; j + gaps[i] < n; j++) {
      for (int k = j; v[k] < v[k + gaps[i]] && k > 0; k--) {
        int x = v[j];
        v[j] = v[j + gaps[i]];
        v[j + gaps[i]] = x;
      }
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
