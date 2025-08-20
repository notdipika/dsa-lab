#include<stdio.h>
#include<math.h>

void Merge(int a[], int l, int m, int r){
    int i = l;
    int j = m;
    int k = l;

    int b[r-l+1];

    while(i < m && j <= r){
        if(a[i] < a[j]){
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    for(; i<m; i++, k++){
        b[k] = a[i];
    }
    for(; j<=r; j++, k++){
        b[k] = a[j];
    }
    for(i=l; i<=r; i++){
        a[i] = b[i];
    }
}

void MergeSort(int a[], int l, int r){
    if(l<r) {
        int mid = floor((float) (l+r)/2);
        MergeSort(a, l, mid);
        MergeSort(a, mid+1, r);
        Merge(a, l, mid+1, r);
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

    int size = sizeof(a)/sizeof(a[0]);

    printArray(a, size);
    MergeSort(a, 0, size-1);
    printArray(a, size);

    return 0;
}