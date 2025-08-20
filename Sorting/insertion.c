#include<stdio.h>

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(int a[], int n){
    for(int i=0; i<n; i++){
        int j = i-1;
        int element = a[i];

        while(j>=0 && element < a[j]){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = element;
    }
}

void printArray(int a[], int size){
    for (int i=0; i<size; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main(){
    int a[] = {4, 3, 7, 1, 5, 8, 2, 6, 10, 9};

    printArray(a, sizeof(a)/sizeof(a[0]));
    InsertionSort(a, sizeof(a)/sizeof(a[0]));
    printArray(a, sizeof(a)/sizeof(a[0]));

    return 0;
}