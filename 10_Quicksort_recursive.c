#include <stdio.h>

#define MAX 10

void acceptData(int list[], int size);
void printList(int list[], int size);

void quickSort(int list[],const int lower_bound,const int upper_bound);
void swap(int list[], int i, int j);
// {2,34,56,7,8,45,3,27,5,9};
int main(void) {
    int list[MAX] = {2,34,56,7,8,45,3,27,5,9};
    int no_of_elements = 10;

//    printf("Please enter the number of elements (max =10 ) in the list : ");
//    scanf("%d", &n);
   // acceptData(list, n);
    printf("The list before sorting is:\n");
    printList(list, no_of_elements);

    quickSort(list, 0, no_of_elements - 1); //array,lowerbound,upperbound

    printf("\nThe list after sorting is:\n");
    printList(list, no_of_elements);
    return 0;
}

void quickSort(int list[], const int lowerBound,const int upperBound) {
    int pivot;
    int i;
    int u;
    
    if (lowerBound < upperBound) {
        pivot = list[lowerBound];
        i = lowerBound + 1;
        u = upperBound;
        while (i <= u) {
            while ((i <= upperBound) && (list[i] < pivot)) {
                i++;
            }
            while ((u >= lowerBound) && (list[u] > pivot)) {
                u--;
            }
            /* when u & l have not crossed or met each other*/
            if (i < u) {
                swap(list, i, u);
            }
//          printList(list, upperBound + 1);
        } //while
        /* when u and l have crossed or met each other*/
        swap(list, lowerBound, u);
        printList(list, upperBound + 1);
        quickSort(list, lowerBound, u - 1); //left sub array
        quickSort(list, u + 1, upperBound); //right sub array
    }
    return;
}

/*Element at ith position is swapped with element at jth Position in the list*/
void swap(int list[], int i, int j) {
    int temp;
    temp = list[i];
    list[i] = list[j];
    list[j] = temp;
    return;
}

void acceptData(int list[], int size) {
    int i;
    printf("Please enter %d elements\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }
    return;
}

void printList(int list[], int size) {
    int i;
//    printf("\nThe elements of the list are: \n");
    for (i = 0; i < size; i++) {
        printf("%d\t", list[i]);
    }
    printf("\n");
}


