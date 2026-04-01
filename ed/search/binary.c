#include <stdio.h>

int binary_search(int size, int arr[size], int target) {
    int first = 0;
    int last = size - 1;
    while (first <= last) {
        int mid = (first + last) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            first = mid + 1;
        else last = mid - 1;
    }
    return -1;
}

int main(void) {
    // note: the array must be sorted
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    int size = sizeof(arr) / sizeof(int);

    int idx = binary_search(size, arr, 5);
    printf("Index: %d\n", idx);
    
    return 0;
}
