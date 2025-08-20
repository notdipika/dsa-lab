#include<stdio.h>

int largest(int arr[], int n){
    int l = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > l)
            l = arr[i];
    }

    return l;
}

void countingSort(int arr[], int n, int base){
    int out[n];
    int count[10] = {0};

    for(int j=0; j<n; j++){
        count[(arr[j]/base)%10]++;
    }

    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }

    for(int j=n-1; j>=0; j--){
        int digit = (arr[j]/base)%10;
        out[count[digit]-1] = arr[j];
        count[digit]--;
    }

    for(int i=0; i<n; i++){
        arr[i] = out[i];
    }
}

void radixSort(int arr[], int n){
    int max = largest(arr, n);
    int base = 1;
    while(max!=0){
        countingSort(arr, n, base);
        base *= 10;
        max/=10;
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {11, 10, 122, 148, 37, 43, 29, 54, 45, 76};
    radixSort(arr, 10);
    print(arr, 10);

    return 0;
}