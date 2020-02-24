#include <stdio.h>
#include <stdlib.h>


int *merge(int *arr1, int size1, int *arr2, int size2)
{
    int *merged_array = malloc(sizeof(int) * (size1 + size2));
    int merged_length = 0;
    int i = 0;
    int k = 0;

    // While merged array not full
    while (merged_length < (size1 + size2)) {

        // If done with arr1
        if (i == size1) {
            // Add arr2 to merged array
            while (k != size2) {
                merged_array[merged_length] = arr2[k];
                k++;
                merged_length++;
            };

        // else if done with arr2
        } else if (k == size2) {
            // Add arr1 to merged_array
            while (i != size1) {
                merged_array[merged_length] = arr1[i];
                i++;
                merged_length++;
            };

        // else if arr1[i] < arr2[k]
      } else if (arr1[i] < arr2[k]) {
            // Add arr1[i] to merged_array
            merged_array[merged_length] = arr1[i];
            i++;
            merged_length++;

        // else if arr2[k] < arr1[i]
      } else if (arr2[k] < arr1[i]) {
            // Add arr2[k] to merged_array
            merged_array[merged_length] = arr2[k];
            k++;
            merged_length++;
        };
    };
    return merged_array;
}


int *merge_sort(int *array, int len)
{
    // Base case: If array len == 0 or 1
    if (len == 1 || len == 0) {
        return array;

    } else {
        int half = len / 2;

        int i = 0;
        int *left = malloc(sizeof(int) * half);
        int *right = malloc(sizeof(int) * (len - half));

        // Copy first half of array to left
        for (i = 0; i < half; i++) {
            left[i] = array[i];
        };

        // Copy second half of array to right
        for (i = half; i < len; i++) {
            right[i - half] = array[i];
        };

        // Do merge sort on left and right and return merged array
        int *sorted_left = merge_sort(left, half);
        int *sorted_right = merge_sort(right, len - half);
        return merge(sorted_left, len / 2, sorted_right, len - (len / 2));
    };
};


int main()
{
    int unsorted[7] = {7, 4, 8, 1, 2, 9, 3};
    unsigned long len = sizeof(unsorted) / sizeof(unsorted[0]);

    int *merged_thing = merge_sort(unsorted, len);
    int q = 0;
    for (q = 0; q < 7; q++) {
      printf("Value %d: %d\n", q, *(merged_thing + q));
    };
    return 0;
}
