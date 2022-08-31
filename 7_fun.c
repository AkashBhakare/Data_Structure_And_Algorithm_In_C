/*Header file containing declaration or definitions of predefiend library function*/
#include <stdio.h>
#include <stdlib.h>

unsigned int stepCount = 0;

long long int sum ( int a[], int size) {
	long long int theSum = 0;
	stepCount++; //for theSum = 0
	for( int i  = 0; i < size; i++ ) {
		stepCount++; //for the for statement
		theSum += a[i]; // a +=b ; a = a +b
		stepCount++; //for the assignment 	}
	}
	stepCount++;//for last execution of loop
	stepCount++;//for the return statement
	return theSum; 	
}

long long int sum_rec(int a[], int size){
	if (size > 1)
	{
		return(a[size-1] + sum_rec(a,size-1));
	}
	else
	{
		return a[0];
	}

}


int search(int a[], int size, int vts){
	int idx;
	for(idx = 0; idx < size; ++idx){
		if(a[idx] == vts){
			return idx+1;
		}
	}
	return 0;

}

int main(void){
	int pos;
	int vts; 
	int buff[] = {2,3,5,6,78,89,5,6,78,993,4,4,4,4,4,4,4,4,5,5,67,34};
	printf("Sum = %lld\n", sum(buff,3));
	printf("The time complexity is %u\n",stepCount);
	printf("Sum = %lld\n", sum_rec(buff,3));
	vts = 55;
	pos = search(buff, 10,vts);
	if(pos !=0 ){
		printf("Found %d at position %d\n", vts,pos);
	}else{
		printf("Didnt find %d\n",vts);
	}
	return EXIT_SUCCESS;
}
