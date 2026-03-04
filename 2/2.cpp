#include <stdio.h>
#include <Windows.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
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

    selectionSort(arr, n);

    printf("Відсортований масив:\n");
    printArray(arr, n);

    return 0;
}
