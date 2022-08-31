
#include <stdio.h>
#include <stdlib.h>

int main() {
    void* vp; //Generic Pointer
    int* ip; //Pointer to integer
    int no_stud;
    int idx;

    printf("Please enter the number of students:");
    scanf("%i", &no_stud);

    vp = malloc(no_stud * sizeof (int));
    if (vp == NULL) //if allocation has failed
    {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
    }
    
    //  proceed only if allocation is successful
    printf("Memory has been successfully allocated\n");
    printf("Starting from address %p\n", vp);
    
    ip = (int*) vp; //cast void* to int*
    
    printf("Please enter the marks of students\n");
    
    for (idx = 0; idx < no_stud; ++idx) {
        printf("Student No %d :", idx + 1);
        scanf("%i", (ip + idx));
    }
    
    printf("Marks of the students are as follows\n");
    for (idx = 0; idx < no_stud; ++idx) {
//        printf("Student No %d\tMarks = %d\n", idx + 1, *(ip + idx));
        printf("Student No %d\tMarks = %d\n", idx + 1, ip[idx]);
    }
    
    //release the block of memory allocated
    if (vp != NULL) {
        free(vp);
        //     free(vp);
        //Handle dangling pointers
        vp = NULL;
        ip = NULL;
    }
    return (EXIT_SUCCESS);
}

