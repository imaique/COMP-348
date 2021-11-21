#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "selectionsort.h"
#include "selectionsort.h"

int* findmin(int* arr, int size);

static int* findmax(int* arr, int size);
int main() {
    // Prompting the number of integers and
    printf("Enter the number of integers you want to input in the program (bigger than 0):");
    int n;
    scanf("%d",&n);
    if (n<1){
        printf("ERROR: Invalid number of integers.");
        return 1;
    }

    // Creating the dynamically allocated array of n integers
    int *dyn_array;
    dyn_array = (int *)malloc(sizeof (int)*n);
    if(dyn_array==NULL){
        printf("ERROR: Out of memory.");
        return 1;
    }

    // Uses user input to declare the elements of the array
    int i;
    for (i = 0; i < n; i++){
        printf("Enter integer #%d%:",i + 1);
        scanf("%d",&dyn_array[i]);
        printf("\n");
    }

    // Prints the inittial array to confirm
    printf("Printing the created array: \n");
    for(i = 0; i < n; i++) printf("%d ", dyn_array[i]);



    printf("\nSorting the array in ascending order: \n");
    selectionsort(dyn_array,n,NULL); //
    for(i = 0; i < n; i++) printf("%d ", dyn_array[i]);

    printf("\nSorting the array in descending order: \n");
    int* (*max_ptr)(int*,int) = &findmax;
    selectionsort(dyn_array,n,max_ptr); //
    for(i = 0; i < n; i++) printf("%d ", dyn_array[i]);

    printf("\nMinimum of the array = %d%\n", *findmin(dyn_array,n));
    printf("\nMaximum of the array = %d%\n", *findmax(dyn_array,n));

    int sum = 0;
    for(i=0; i<n; i++) sum+= dyn_array[i];
    float avg = (float)sum/n;
    printf("\nAverage of the array = %.2f%\n", avg);

    float stddev, sumdev = 0.0;
    for(i=0; i<n; i++) {
        float current = (dyn_array[i]-avg);
        sumdev += current*current;
    }
    stddev = sqrt(sumdev/n);
    printf("\nStandard deviation of the array = %.2f%\n", stddev);
    return 0;
}
int* findmin(int* arr, int size){
    int* minpointer = arr;
    int i;
    for(i = 1; i< size; i++){
        if(*minpointer>*(arr+i)){
            minpointer = arr + i;
        }
    }
    return minpointer;
}
static int* findmax(int* arr, int size){
    int* maxpointer = arr;
    int i;
    for(i = 1; i< size; i++){
        if(*maxpointer<*(arr+i)){
            maxpointer = arr + i;
        }
    }
    return maxpointer;
}
