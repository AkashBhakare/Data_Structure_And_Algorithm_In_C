
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 10
/*
 * Insertion Sort implementation
 */
void insertionSort(int [ ], size_t);
void insertion_sort(int [], size_t);
void printArray(int [], size_t);
void acceptSet(int[], size_t);

int main(void) {
    int arr[ SIZE ] = {12,34,56,78,3,2,1,4,5,9};
    //acceptSet(arr, SIZE);
    printf("The original numbers are :\n");
    printArray(arr, SIZE);
    insertion_sort(arr, SIZE);
    printf("The sorted numbers are :\n");
    printArray(arr, SIZE);
    return (EXIT_SUCCESS);
}

void printArray(int a[], size_t size) {
 
    for (int i = 0; i < size; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n");
}

void acceptSet(int arr[], size_t size) {
    int i;
    printf("\nPlease enter %d integers : \n", SIZE);
    for (i = 0; i < size; i++) {
        printf("Value no. %2d :", i + 1);
        scanf("%d", &arr[i]);
    }
    return;
}

void insertion_sort(int arr[], size_t size) {
    int position;
    int currentvalue;

    for (int index = 1; index < size; index++) {
        currentvalue = arr[index];
        position = index;
        while (position > 0 && (arr[position - 1] > currentvalue)) {
            arr[position] = arr[position - 1];
            position = position - 1;
        }
        arr[position] = currentvalue;

    }
}


void insertionSort(int arr[], size_t size) {
    int i;
    int j;
    int k;
    int temp;
    for (i = 1; i < size; i++) {
        for (j = 0; j < i; j++) {
            if (arr[ i ] > arr[ j ]) {
                temp = arr[ i ];
                k = i;
                while (k > j) //shifting elements
                {
                    arr[ k ] = arr[ k - 1 ];
                    k--;
                } //end while
                arr[j] = temp;
                break;
            } //end if
        } //end of j for loop
    } //end of i for loop
    return;
}


