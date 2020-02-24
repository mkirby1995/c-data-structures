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
            // while k != size2
            while (k != size2) {
                // Add arr2[k] to merged_array
                *(merged_array + merged_length) = *(arr2 + k);
                // increment k and merged_length
                k ++;
                merged_length ++;
            };
        // else if done with arr2
        } else if (k == size2) {
            // while i != size1
            while (i != size1) {
                // Add arr1[i] to merged_array
                *(merged_array + merged_length) = *(arr1 + i);
                // increment i and merged_length
                i ++;
                merged_length ++;
            };
        // else if arr1[i] < arr2[k]
        } else if (*(arr1 + i) < *(arr2 + k)) {
            // Add arr1[i] to merged_array
            *(merged_array + merged_length) = *(arr1 + i);
            // Increment i and merged_length
            i ++;
            merged_length ++;
        // else if arr2[k] < arr1[i]
        } else if (*(arr2 + k) < *(arr1 + i)) {
            // Add arr2[k] to merged_array
            *(merged_array + merged_length) = *(arr2 + k);
            // Increment k and merged_length
            k ++;
            merged_length ++;
        };
    };

    return merged_array;
}

int main()
{
    int arr_a[2] = {1, 3};
    int arr_b[2] = {2, 5};

    int *merged_array = merge(arr_a, 2, arr_b, 2);

    int x = 0;
    for (x = 0; x < 4; x++) {
      printf("Value %d: %d\n", x, *(merged_array + x));
    }

    return 0;
}
