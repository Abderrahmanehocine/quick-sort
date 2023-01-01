#include <stdio.h>

void swap(int *n1, int *n2){
    int n = *n1;
    *n1 = *n2;
    *n2 = n;
}

int partition(int *arr, int start, int end){
    int pivot = arr[end];
    int pIndex = start;
    int i;
    for(i=start; i<end; i++){
        if(arr[i] <= pivot){
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[pIndex], &arr[end]);
    return pIndex;
}

void quickSort(int *arr, int start, int end){
    if(start < end){
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

int main(){
    int size;
    printf("Enter number of numbers: ");
    scanf("%d",&size);
    int list[size];
    int i;
    for(i=0 ; i<size ; i++){
        printf("Enter a number: ");
        scanf("%d",&list[i]);
    }
    quickSort(list, 0,size-1);
    for(i=0 ; i<size ; i++)
        printf("%d ",list[i]);
    printf("\n");
}