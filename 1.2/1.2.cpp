#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX_RANDOM_VALUE 10000
#define REPEATS_COUNT 10000

void fillArrayWithRandom(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % MAX_RANDOM_VALUE;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int sizes[] = { 100, 1000, 10000 };
    int numSizes = sizeof(sizes) / sizeof(sizes[0]); 
    srand((unsigned int)time(NULL));

    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];

        int* arr = (int*)malloc(n * sizeof(int));
        int* temp = (int*)malloc(n * sizeof(int));

        if (arr == NULL || temp == NULL) {
            printf("Помилка: не вдалося виділити пам'ять!\n");
            return 1;
        }

        double totalTime = 0;
        int repeats = (n == 10000) ? 1 : REPEATS_COUNT;

        for (int r = 0; r < repeats; r++) {
            fillArrayWithRandom(arr, n);

            for (int i = 0; i < n; i++)
                temp[i] = arr[i];

            clock_t start = clock();
            insertionSort(temp, n);
            clock_t end = clock();

            totalTime += (double)(end - start) / CLOCKS_PER_SEC * 1000;
        }

        printf("Сортування вставками: %d елементів — %.5f мс\n", n, totalTime / repeats);

        free(arr);
        free(temp);
    }

    return 0;
}