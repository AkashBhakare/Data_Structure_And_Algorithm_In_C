
#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int size);
void merge(int a[ ], int tmp_array[ ], int l_pos, int r_pos, int right_end);
void mergesort(int a[], unsigned int n);
void m_sort_rec(int a[], int tmp_array[ ], int left, int right);

/*
 * Implementation of merge sort
 */
int main(void) {
    int a[] = {1, -5, 4, 2, 8, 7, 5, -1, 3};
    mergesort(a, 9);
    printArray(a, 9);
    return (EXIT_SUCCESS);
}

void printArray(int a[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }
}

void merge(int a[ ], int tmp_array[ ], int l_pos, int r_pos, int right_end) {

    int i;
    int left_end;
    int num_elements;
    int tmp_pos;
    left_end = r_pos - 1;
    tmp_pos = l_pos;
    num_elements = right_end - l_pos + 1;

    /* main loop */

    while ((l_pos <= left_end) && (r_pos <= right_end)){
        if (a[l_pos] <= a[r_pos])
            tmp_array[tmp_pos++] = a[l_pos++];
        else
            tmp_array[tmp_pos++] = a[r_pos++];
    }
    
    while (l_pos <= left_end){ /* copy rest of first half */
        tmp_array[tmp_pos++] = a[l_pos++];
    }
    
    while (r_pos <= right_end){ /* copy rest of second half */
        tmp_array[tmp_pos++] = a[r_pos++];
    }
    
    /* copy tmp_array back */
    for (i = 1; i <= num_elements; i++, right_end--){
        a[right_end] = tmp_array[right_end];
    }

}

/*Alternate implementation using recursion*/

void mergesort(int a[], unsigned int n) {
    int *tmp_array;
    tmp_array = (int *) malloc((n + 1) * sizeof (int));
    if (tmp_array != NULL) {
        m_sort_rec(a, tmp_array, 0, n - 1);
        free(tmp_array);
    } else
        fprintf(stderr, "No space for temp array");
    //fatal_error("No space for tmp array!!!");
}

void m_sort_rec(int a[], int tmp_array[ ], int left, int right) {
    int center;
    if (left < right) {
        center = (left + right) / 2;
        m_sort_rec(a, tmp_array, left, center);
        m_sort_rec(a, tmp_array, center + 1, right);
        merge(a, tmp_array, left, center + 1, right);
    }
}
