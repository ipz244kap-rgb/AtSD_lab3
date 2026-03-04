#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define REPEATS 10000

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        if (minIdx != i) {
            int tmp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = tmp;
        }
    }
}

void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int sizes[] = { 100, 1000, 10000 };
    srand(time(NULL));

    for (int s = 0; s < 3; s++) {
        int n = sizes[s];
        int repeats = (n == 10000) ? 1 : REPEATS;

        int* arr = (int*)malloc(n * sizeof(int));
        int* temp = (int*)malloc(n * sizeof(int));

        double totalTime = 0;
        for (int r = 0; r < repeats; r++) {
            fillRandom(arr, n);
            for (int i = 0; i < n; i++)
                temp[i] = arr[i];

            clock_t start = clock();
            selectionSort(temp, n);
            clock_t end = clock();

            totalTime += (double)(end - start) / CLOCKS_PER_SEC * 1000;
        }

        printf("—ортуванн€ вибором: %d елемент≥в Ч %.5f мс\n", n, totalTime / repeats);

        free(arr);
        free(temp);
    }

    return 0;
}
