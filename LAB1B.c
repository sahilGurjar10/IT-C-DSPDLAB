#include <stdio.h>
#include <stdlib.h>

int* binarySearch(int* arr, int size, int target) {
    if (arr == NULL || size == 0) return NULL;
    int start = 0, end = size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        printf("%d\n", arr[mid]);
        if (arr[mid] == target) return arr + mid;
        else if (arr[mid] < target) {
            start = mid + 1;
            printf("%d\n", mid);
        } else {
            end = mid - 1;
            printf("%d\n", mid);
        }
    }
    return NULL;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int* result = binarySearch(arr, size, target);
    if (result != NULL) printf("Found %d\n", *result);
    else printf("Not found\n");
    return 0;
}
