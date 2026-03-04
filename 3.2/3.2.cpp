#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define MAX_VALUE 20000  
#define REPEATS 1000    

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];

    int* count = (int*)calloc(max + 1, sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));
    if (!count || !output) {
        printf("Помилка виділення пам'яті!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(count);
    free(output);
}

void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % MAX_VALUE;
}

double measureAverageTime(int n, int repeats) {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);

    int* arr = (int*)malloc(n * sizeof(int));
    int* temp = (int*)malloc(n * sizeof(int));
    if (!arr || !temp) {
        printf("Помилка виділення пам'яті!\n");
        exit(1);
    }

    double totalMs = 0;
    for (int r = 0; r < repeats; r++) {
        fillRandom(arr, n);
        for (int i = 0; i < n; i++)
            temp[i] = arr[i];

        QueryPerformanceCounter(&start);
        countingSort(temp, n);
        QueryPerformanceCounter(&end);

        totalMs += (double)(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
    }

    free(arr);
    free(temp);
    return totalMs / repeats;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned int)time(NULL));

    int sizes[] = { 100, 1000, 10000 };

    for (int i = 0; i < 3; i++) {
        int n = sizes[i];
        double avgTime = measureAverageTime(n, REPEATS);
        printf("Сортування підрахунком — %5d елементів: %.5f мс \n",
 n, avgTime);
    }

    return 0;
}
