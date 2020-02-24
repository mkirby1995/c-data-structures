#include <stdio.h>
#include <stdlib.h>

int main()
{

    int unsorted[] = {1};

    // Find the length of the array
    unsigned long len = sizeof(unsorted) / sizeof(unsorted[0]);
    printf("Length of unsorted array: %lu\n", len);

    // Calculate the halfway point
    int half = len / 2;
    printf("Halfway: %d\n", half);

    // Initialize an increment, left array, and right array
    int i = 0;
    int *left = malloc(sizeof(int) * half);
    int *right = malloc(sizeof(int) * (len - half));

    // Copy first half of array to left
    for (i = 0; i < half; i++) {
        *(left + i) = *(unsorted + i);
        printf("Step: %d \tInserting: %d \n", i, *(unsorted + i));
    };
    printf("Right created.\n");

    // Copy second half of array to right
    for (i = half; i < len; i++) {
        *(right + i - half) = *(unsorted + i);
        printf("Step: %d \tInserting: %d \n", i, *(unsorted + i));
    };
    printf("Left created.\n");
    free(left);
    free(right);
    return 0;
}
