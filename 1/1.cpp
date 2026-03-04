#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define MAX 100

void countingSort(int arr[], int n) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[MAX] = { 0 };

    if (output == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return;
    }

    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

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

    free(output);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr[] = { 5, 2, 9, 1, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Початковий масив:\n");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Відсортований масив:\n");
    printArray(arr, n);

    return 0;
}
