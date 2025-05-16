#include<stdio.h>

void printArray(int n, int v[]) {
  for(int i = 0; i < n; i++) {
    printf("%i) %ikm/h\n", i + 1, v[i]);
  }
}

void merge(int v[], int left, int mid, int right) {
  int size = right - left + 1;
  int aux[size];
  int i = left, j = mid + 1, k = 0;

  while(i <= mid && j <= right) {
    if(v[j] >= v[i]) {
      aux[k++] = v[j++];
    } else {
      aux[k++] = v[i++];
    }
  }

  while (i <= mid) {
    aux[k++] = v[i++];
  }

  while (j <= right) {
    aux[k++] = v[j++];
  }

  for (int l = 0; l < size; l++) {
    v[left + l] = aux[l];
  }
}

void mergeSort(int v[], int start, int end) {
  int mid = (start + end) / 2;
  if (start < end) {
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
  }
  merge(v, start, mid, end);
}

int main() {
  int v[] = {331,326,333,330,329,319,325};
  int vSize = sizeof(v) / sizeof(v[0]);
  mergeSort(v, 0, vSize - 1);

  printArray(vSize, v);

  return 0;
}
