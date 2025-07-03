#include<stdio.h>
#include<math.h>

typedef struct {
    int speed;
    char team[32];
} TeamSpeed;

void printArray(int n, TeamSpeed v[]) {
    for(int i = 0; i < n; i++) {
        printf("%i) %s: %ikm/h\n", i + 1, v[i].team, v[i].speed);
    }
}

int generateHibbardGaps(int n, int gaps[]) {
  int i = 0;
  while ((1 << (i + 1)) - 1 < n) {
    gaps[i++] = (1 << (i + 1)) - 1;
  }
  return i;
}

void shellSort(TeamSpeed v[], int n, int gaps[], int gapsSize) {
    for (int i = gapsSize - 1; i >= 0; i--) {
        for (int j = 0; j + gaps[i] < n; j++) {
            int k = j;
            while (k >= 0 && v[k].speed < v[k + gaps[i]].speed) {
                TeamSpeed x = v[k];
                v[k] = v[k + gaps[i]];
                v[k + gaps[i]] = x;
                if (k - gaps[i] >= 0) k -= gaps[i];
                else break;
            }
        }
    }
}

int main() {
    TeamSpeed array[] = {
        {331, "Red Bull"},
        {326, "Ferrari"},
        {333, "Mercedes"},
        {330, "McLaren"},
        {329, "Aston Martin"},
        {319, "Alpine"},
        {325, "Williams"},
        {308, "AlphaTauri"},
        {324, "Alfa Romeo"},
        {310, "Haas"}
    };

    int gaps[32];
    int arraySize = sizeof(array) / sizeof(array[0]);
    int gapsSize = generateHibbardGaps(arraySize, gaps);

    shellSort(array, arraySize, gaps, gapsSize);

    printArray(arraySize, array);

    return 0;
}
