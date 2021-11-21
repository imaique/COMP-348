//
// Created by Michael on 2021-06-13.
//

#ifndef Q9_SELECTIONSORT_H
#define Q9_SELECTIONSORT_H


extern int* findmin(int*,int);
void selectionsort(int arr[],int n,int* (*ptr)(int*,int)){
    if(ptr==NULL){
        ptr = &findmin;
    }
    int* sublistpointer = &arr[0];
    int i;
    for(i=0;i<n;i++){
        int *min = ptr(&arr[i],n-i);
        int value = *min;
        *min = *(sublistpointer + i);
        *(sublistpointer + i) = value;
    }
}

#endif //Q9_SELECTIONSORT_H
