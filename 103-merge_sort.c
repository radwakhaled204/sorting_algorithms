#include "sort.h"

/**
 * merge - Merge two subarrays into a single sorted array.
 * @array: Pointer to the array.
 * @l: Index of the left subarray.
 * @m: Index of the middle element.
 * @r: Index of the right subarray.
 */
void merge(int *array, size_t l, size_t m, size_t r) {
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    int *L = (int *)malloc(sizeof(int) * n1);
    int *R = (int *)malloc(sizeof(int) * n2);

    size_t i, j, k;
    for (i = 0; i < n1; i++) {
        L[i] = array[l + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = array[m + 1 + j];
    }

    i = j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

/**
 * merge_sort_recursive - Recursive function to perform Merge Sort.
 * @array: Pointer to the array.
 * @l: Index of the left subarray.
 * @r: Index of the right subarray.
 */
void merge_sort_recursive(int *array, size_t l, size_t r) {
    if (l < r) {
        size_t m = l + (r - l) / 2;
        merge_sort_recursive(array, l, m);
        merge_sort_recursive(array, m + 1, r);
        merge(array, l, m, r);
    }
}

/**
 * merge_sort - Sort an array of integers using the Merge Sort algorithm.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size) {
    if (size > 1) {
        merge_sort_recursive(array, 0, size - 1);
    }
}

/* O(n log n) for best, average, and worst cases */

