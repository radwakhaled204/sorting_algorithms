#include "sort.h"

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

    printf("Merging...\n[left]: ");
    print_array(L, n1);
    printf("[right]: ");
    print_array(R, n2);

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

    printf("[Done]: ");
    print_array(array + l, n1 + n2);

    free(L);
    free(R);
}

void merge_sort(int *array, size_t size) {
    if (size > 1) {
        size_t m = size / 2;
        merge_sort(array, m);
        merge_sort(array + m, size - m);
        merge(array, 0, m - 1, size - 1);
    }
}

