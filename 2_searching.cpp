// 1.	Binary search using array (recursive method)
// 2.	Binary search using array (Non recursive)
// 3. 	Linear sequential search in sorted array
// 4. 	Linear sequential search in unsorted array
// 5. 	Sorting (selection)
// 6.   Sequential Search with Sentinal
// 7.   Fibonacci Search

#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include <limits.h>
#define SIZE 10U

void sort(int[]);
void accept(int[]);
void display(int[]);
void binarySearch(int arr[], int target, size_t arraySize);
void recursiveBinarySearch(int [], int, int, int);
void linearSearchSorted(int array[], int target, size_t arraySize);
void linearSearchUnsorted(int [], int, size_t ); //for unsorted array
void sequentialSentinalSearch(int array[], int target, size_t arraySize);
int fibonacciSearch(int [], size_t arraySize, int target);

int main(void) {
//    int arr[SIZE] = {12, 43, 56, 78, 34, 67, 6, 3, 2, 8};
    int arr[] = {7,9,12,15,19,27,28,32,35,45,55,61,65,77};

    int target = 32;
    accept(arr);
    printf("Please enter the number to be searched ");
    scanf("%d", &target);
    linearSearchUnsorted(arr, target, SIZE);
    sequentialSentinalSearch(arr, target, SIZE);
    sort(arr);
    display(arr);
    linearSearchSorted(arr, target, (sizeof (arr)) / sizeof (arr[0]));
    linearSearchSorted(arr, target, SIZE);
    binarySearch(arr, target, SIZE);
    recursiveBinarySearch(arr, target, 0, (SIZE - 1));
     
    int pos = fibonacciSearch(arr, (sizeof (arr)) / sizeof (arr[0]), target);

    if (pos >= 0) {
        printf("%d found at index %d\n", target, pos);
    } else{
        printf("%d was not found\n", target);
   }
    return EXIT_SUCCESS;
}

//sequential search in a unsorted array

void linearSearchUnsorted(int arr[ ], int target, size_t size) {
    int idx;    //index for the array
    bool found = false;
    // Traverse through the array
    for (idx = 0; idx < size; ++idx) {
        // compare element at idx position in the array with the target
        if (arr[idx] == target) {
            found = true;
            break;  // Terminate the loop if target is found
        }
    }
    //Check if the search was successful
    if (found == true) {
        printf("The number %d is found at position %d\n", target, (idx + 1));
    } else {
        printf("Number %d is not found!\n", target);
    }
    return;
}


void accept(int arr[ SIZE ]) {
    int i;
    printf("\nPlease enter %d integer values : ", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("\nPlease enter the integer no %d :", (i + 1));
        scanf("%d", &arr[ i ]);
    }
    return;
}

void sort(int arr[SIZE]) {
    int i;
    int j;
    int temp;
    //sorting (selection sort)
    for (i = 0; i < SIZE; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (arr[ i ] > arr [ j ]) {
                //swap
                temp = arr[ i ];
                arr[ i ] = arr[ j ];
                arr[ j ] = temp;
            }
        }
    }
    return;
}

void display(int arr[SIZE]) {
    size_t i;
    printf("\nThe contents of the array are : \n");
    for (i = 0; i < SIZE; i++) {
        printf("Element No %zu : %d\n", i + 1, arr[ i ]);
    }
    return;
}

void recursiveBinarySearch(int arr[], int target, int lower, int upper) {
    int mid;
    if (lower <= upper) {
        mid = (upper + lower) / 2;
        if (arr[ mid ] == target) {
            printf("Found at position %d\n", mid + 1);
            return;
        }
        if (arr[ mid ] > target) {
            recursiveBinarySearch(arr, target, lower, (mid - 1));
        } else {
            recursiveBinarySearch(arr, target, (mid + 1), upper);
        }
    } else {
        printf("The number is not present in the list\n");
    }
    return;
}

void binarySearch(int arr[], int target, size_t arraySize) {
    int mid; // mid point
    int upper = (arraySize - 1); // upper bound of array
    int lower = 0; // lower bound of array

    while (lower <= upper) {
        mid = (upper + lower) / 2; // find the mid point 
        //Compare the element at mid point with the target
        if (arr[ mid ] == target) {
            printf("Found at position %d\n", mid + 1);
            break; //terminate search if target is found
        }
        
        //If element at mid point is larger than the target
        if (arr[ mid ] > target) {
            // change the upper bound of section of array to be searched
            upper = mid - 1;
        } else {//If element at mid point is smaller than the target
            //change the lower bound of section of array to be searched
            lower = mid + 1;
        }
    }//end of while loop
    if (lower > upper) {
        printf("%d is not found in the array\n", target);
    }
    return;
}

//sequential search in a array sorted in ascending order

void linearSearchSorted(int arr[], int target, size_t arraySize) {
    // arr = {7,9,12,15,19,27,28,32,35,45,55,61,65};
    size_t idx; //index for the array
    bool foundTarget = false;
    //proceed with search only if the target is not larger than the last element
    if (target <= arr[arraySize - 1]) {
        for (idx = 0; idx < arraySize; idx++) {
            // compare(for Equality) element at 
            // idx position in the array with the target
            if (arr[idx] == target) {
                foundTarget = true;
                break; // Terminate the search if target is found
            } else {
                if (arr[idx] > target) {
                    // Terminate the search if element at idx position in the
                    // array is larger than the target
                    break;
                }
            }
        }
    }
    //Check if the search was successful
    if (foundTarget == true) {
        printf("The number %d is found at position %zu\n", target, (idx + 1));
    } else {
        printf("Number %d is not found!\n", target);
    }
    return;
}

/*Search that avoids checking array bounds*/
void sequentialSentinalSearch(int arr[], int target, size_t arraySize) {
    int lastElement = arr[arraySize - 1];
    int idx = 0;
    //Replace the last element in the array with the target
    arr[arraySize - 1] = target;
    // Search for the target in the array sequentially 
    // starting from first position
    while (arr[idx] != target); 
    {
        idx++; //increment the idx if matching element is not found
    }
    // Restore the last element in the array
    arr[arraySize - 1] = lastElement;
    // if the element is found
    if (arr[idx] == target) {
        printf("Element found at Position %d\n", (idx + 1));
    } else {
        printf("Element is not Present\n");
    }
    return;
}

int fibonacciSearch(int arr[], size_t arraySize, int target) {
    int k;
    int idx;
    int offs;
    /*  Precomputed Fibonacci numbers F0 up to F46. This implementation assumes 
     *  that the size n of the input array fits in 4 bytes. 
     *  Note that F46 = 1836311903 is the largest Fibonacci number that is less 
     *  or equal to the 4-byte INT_MAX (=2147483647). 
     *  The next Fibonacci number, i.e. F47, is 2971215073 and is larger 
     *  than INT_MAX, implying that it does not  fit in a 4 byte integer. 
     *  Note also that the last array element is INT_MAX rather than F47. 
     *  This ensures correct operation for n > F46.
     */
    const static int fib[47 + 1] = {0, 1, 1, 2, 3, 5, 8, 13, 21,
        34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584,
        4181, 6765, 10946, 17711, 28657, 46368, 75025,
        121393, 196418, 317811, 514229, 832040, 1346269,
        2178309, 3524578, 5702887, 9227465, 14930352,
        24157817, 39088169, 63245986, 102334155,
        165580141, 267914296, 433494437, 701408733,
        1134903170, 1836311903, INT_MAX};

    /* Find the smallest fibonacci number that is greater or
     * equal to arraySize. Store this number to avoid recomputing
     * it in the case of repetitive searches with identical arraySize.
     */
    for (k = 0; fib[k] < arraySize; k++);
    /* If the sought value is larger than the largest Fibonacci number 
     * less than arraySize, care must be taken top ensure that we do not attempt 
     * to read beyond the end of the array. If we do need to do this,
     * we pretend that the array is padded with elements larger than the 
     * sought value.
     */
    for (offs = 0; k > 0;) {
        idx = offs + fib[--k];

        /* note that at this point k  has already been decremented once */
        if (idx >= arraySize || target < arr[idx]) {
            // index out of bounds or target in 1st part
            continue;
        }

        if (target > arr[idx]) { // target in 2nd part
            offs = idx;
            --k;
        } else { // target == arr[idx], found
            return idx;
        }
    }

    return -1; // not found
}


// alternative implementation of Fibonacci search
int fibonacci_search(int list[], int n, int a) {
    int f1, f2, mid, first, index;

    f1 = 1;
    f2 = 0;
    mid = 2; //initialise the first two fibonacci
    //numbers. F1 will be the main
    while (f1 < n) { //set F1 to a number >= n
        f1 = f1 + f2;
        f2 = f1 - f2;
        mid++;
    }
    f2 = f1 - f2; //set F1 to the largest number <=n
    f1 = f1 - f2;
    mid--;
    first = 0;

    while (mid > 0) { //loop
        index = first + f1;
        printf("\nfirst:%d,index:%d,f1:%d,list:%d,mid:%d,a:%d",
                first, index, f1, list[index], mid, a);
        if (index >= n || a < list[index]) {
            mid--; //if the number is bigger, move back
            f2 = f1 - f2; //to a smaller fibonacci number
            f1 = f1 - f2;
        } else {
            if (a == list[index]) { //found: return the index
                return (index);
            } else {
                first = index; //if the number is smaller, move to the
                mid = mid - 2; //second part of the list and
                f1 = f1 - f2; //reduce F1 back two F-numbers
                f2 = f2 - f1;
            }
        }
    }

    return (-1); //bad luck: not found
}

