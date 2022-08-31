
/* 
 * File:   working.c
 * Author:  Akash
 *
 * Created on 28 July 2022, 9:43 pm
 * Bubble sort
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Bubble
 */

void bubble_sort(int data[], const int size);
void print_data(int data[], const int size);

int main(int argc, char** argv) {
    const int SIZE = 10;
    int data[] = {12, 34, 56, 2, 4, 1, 6, 8, 9, 22};
    printf("Original data:\n");
    print_data(data, SIZE);

    bubble_sort(data,SIZE);

    printf("Sorted data:\n");
    print_data(data, SIZE);
    return (EXIT_SUCCESS);
}

void bubble_sort(int data[], const int size) {
    int temp;
    
    for (int i = 1; i < size; ++i) { //number of passes
        //perform 1 comparison less at every next pass
        for (int j = 0; j < size-i; ++j) {
            //if (data[j] < data[j + 1]) { //Decending order
            if (data[j] > data[j + 1]) {  //Acending order
            	temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
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

