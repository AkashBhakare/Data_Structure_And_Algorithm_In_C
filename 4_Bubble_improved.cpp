
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
 * Bubble
 * Unnecessary comparison can be avoided is the data is sorted
 */

void bubble_sort(int data[], const int size);
void print_data(int data[], const int size);

size_t comparison_counter = 0;

int main(int argc, char** argv) {
    const int SIZE = 10;
   // int data[] = {12, 34, 56, 2, 4, 1, 6, 8, 9, 22};
     int data[] = { 56, 34, 22, 2, 9, 8, 6, 4, 2, 1};

    printf("Original data:\n");
    print_data(data, SIZE);

    bubble_sort(data,SIZE);

    printf("Sorted data after %u comparison :\n",comparison_counter);
    print_data(data, SIZE);
    return (EXIT_SUCCESS);
}

void bubble_sort(int data[], const int size) {
    int temp;
    bool is_data_sorted;
    
    for (int i = 1; i < size; ++i) { //number of passes
       is_data_sorted = true;
       for (int j = 0; j < size-i; ++j) {
       // for (int j = 0; j > size-i; ++j) {
            comparison_counter++;
            if (data[j] < data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                is_data_sorted = false;
            }
        }
        if(is_data_sorted){
            break;
        }
    }
    return;
}

void print_data(int data[], const int size) {
    printf("\n\t");
    for (int idx = 0; idx < size; ++idx) {
        printf("%d, ", data[idx]);
    }
    printf("\n");
}
