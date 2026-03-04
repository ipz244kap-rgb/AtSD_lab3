#include <stdio.h>
#include <Windows.h>
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

    insertionSort(arr, n);

    printf("Відсортований масив:\n");
    printArray(arr, n);

    return 0;
}
