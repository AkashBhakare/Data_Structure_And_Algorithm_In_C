#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

// Function implementing the Counting Sort
void counting_sort(int unsorted[], int sorted[], size_t array_size);

void print_array(int array[], size_t size);

// The main function

int main() {

    // Initializing the array
    int unsorted_array[] = {5, 2, 5, 3, 6, 1, 5, 3, 9, 6};
    //    printf("%zu\n",sizeof(unsorted_array)); // Amount of memory allocated for the entire array
    //    printf("%zu\n",sizeof(unsorted_array[0])); // Amount of memory allocated for the first element of the array
    // Size of the array

    size_t array_size = sizeof (unsorted_array) / sizeof (unsorted_array[0]);

    // since C99; we can use variable to specify size of array
    int sorted_array[array_size];
    // Function call to the sorting function
    counting_sort(unsorted_array, sorted_array, array_size);

    printf("The Un-sorted array is as follows : ");
    print_array(unsorted_array, array_size);

    printf("The Sorted array is as follows : ");
    print_array(sorted_array, array_size);
    return 0;
}

// Function implementing the Counting Sort

void counting_sort(int unsorted[], int sorted[], size_t array_size) {

    // Step 1: Finding the maximum element
    int maximum = -1;

    for (int i = 0; i < array_size; i++) {
        maximum = fmax(unsorted[i], maximum);
    }

    // Step 2: Initialize a count array of length = (max + 1) 
    int freq_count[maximum + 1] ;
    /*Initialize the array with zero*/
    memset(freq_count, 0, sizeof (freq_count));
    /*
     * If you don't want to use memset then you could iterate through the array
     * and set all elements to zero
    for (int i = 0; i < (maximum + 1); i++) {
        freq_count[i] = 0;
    }
    */
    
    // Step 3: Fill the freq_count array accordingly

    for (int i = 0; i < array_size; i++) {
        freq_count[unsorted[i]]++;
    }

    // Step 4: Calculate cumulative frequency in Count Array

    for (int i = 1; i <= maximum; i++) {
        freq_count[i] += freq_count[i - 1];
    }

    // Step 5: Fix the values in the sorted array

    for (int i = 0; i < array_size; i++) {
        freq_count[unsorted[i]]--;
        sorted[freq_count[unsorted[i]]] = unsorted[i];
    }
    return;
}

void print_array(int array[], size_t size) {
    for (int idx = 0; idx < size; ++idx) {
        printf("%d, ", array[idx]);
    }
    printf("\n");
    return;

}
