
#include<stdio.h>
#include<stdlib.h>

void print_data(int data[], const int size);
void selectionSort(int arr[], int size);
void swap(int arr[], int initial_pos, int subsequent_pos);
    

int main() {

  //  int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int a[10] = {10, 19, 28, 7, 16, 15, -4, 3, 12, 11};
    printf("Original data : \n\t");
    print_data(a, 10 );
    selectionSort(a, 10);
    printf("Sorted data : \n\t");
    print_data(a, 10 );
    printf("\n");
    return 0;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                swap(arr,i,j);
            }
        }
    }
}

void swap(int arr[], int initial_pos, int subsequent_pos){
    int temp            = arr[initial_pos];
    arr[initial_pos]    = arr[subsequent_pos];
    arr[subsequent_pos] = temp;
}

void print_data(int data[], const int size) {
    printf("\n\t");
    for (int idx = 0; idx < size; ++idx) {
        printf("%d, ", data[idx]);
    }
    printf("\n");
}
