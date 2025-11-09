#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
} Array;

int main() {
    Array arr;
    int i, sumOdd = 0, sumEven = 0;
    printf("Enter number of elements: ");
    scanf("%d", &arr.size);
    arr.data = (int*)malloc(arr.size * sizeof(int));
    printf("Enter %d numbers:\n", arr.size);
    for (i = 0; i < arr.size; i++)
        scanf("%d", &arr.data[i]);
    for (i = 0; i < arr.size; i++) {
        if ((i + 1) % 2 == 0)
            sumEven += arr.data[i];
        else
            sumOdd += arr.data[i];
    }
    printf("Sum of numbers at odd positions: %d\n", sumOdd);
    printf("Sum of numbers at even positions: %d\n", sumEven);
    free(arr.data);
    return 0;
}
