#include <stdio.h>

int linear_search(int size, int arr[size], int target) {
    for (int i = 0; i < size; i++) 
        if (arr[i] == target) return i;
    return -1;
}

int main(void) {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(int);

    int idx = linear_search(size, arr, 6);
    printf("Size: %d - Index: %d\n", size, idx);
    
    return 0;
}
