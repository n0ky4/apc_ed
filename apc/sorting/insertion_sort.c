#include <stdio.h>
#include <string.h>

// para usar ordem decrescente, trocar o sinal do key < arr[j]...
void insertion_sort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (key < arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// insertion sort para ordenar alfabeticamente
void insertion_sort_str(char arr[][100], int size) {
    int i, j;
    char key[100];
    for (i = 1; i < size; i++) {
        strcpy(key, arr[i]);
        int j = i - 1;
        while ((j >= 0) && (strcmp(arr[j], key) > 0)) {
            strcpy(arr[j+1], arr[j]);
            j--;
        }
        strcpy(arr[j + 1], key);
    }
}

int main(void) {
    int arr[] = { 12, 564, 6, 2, 765, 3, 54, 7, 2, 76, 35, 76, 1, 3659, 87 };
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
