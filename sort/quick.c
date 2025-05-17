#include<stdio.h>

void printArray(int n, int v[]) {
  for(int i = 0; i < n; i++) {
    printf("%i) %ikm/h\n", i + 1, v[i]);
  }
}

int split(int v[], int start, int end) {
  int pivotValue = v[end];
  int newPivotPos = start;
  for (int i = start; i < end; i++)
    if (v[i] >= pivotValue) {
      int x = v[newPivotPos];
      v[newPivotPos] = v[i];
      v[i] = x;
      newPivotPos++;
    }
  v[end] = v[newPivotPos];
  v[newPivotPos] = pivotValue;

  return newPivotPos;
}

void quickSort(int v[], int start, int end) {
  if (start < end) {
    int mid = split(v, start, end);
    quickSort(v, start, mid -1);
    quickSort(v, mid + 1, end);
  }
}

int main() {
  int v[] = {331,326,333,330,329,319,325};
  int vSize = sizeof(v) / sizeof(v[0]);
  quickSort(v, 0, vSize - 1);

  printArray(vSize, v);

  return 0;
}
