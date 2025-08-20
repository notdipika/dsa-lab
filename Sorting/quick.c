#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define MAX 200000

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r){
    int x=l, y=r;
    int temp;
    int pivot = arr[l];
    while(x < y){
        while(arr[x] <= pivot && x<=r){
            ++x;
        }
        while(arr[y] > pivot && y >=l){
            --y;
        }
        if(x < y){
            temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
        }
    }

   
    arr[l] = arr[y];
    arr[y] = pivot;
    return y;
}

void quick_sort(int arr[], int l, int r){
    if(l<r){
        int p = partition(arr, l, r);
        quick_sort(arr, l, p-1);
        quick_sort(arr, p+1, r);
    }

}


void display(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int i, a[MAX], n;

    srand(time(NULL));
    time_t t1, t2;
    double d;

    printf("Enter n: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        a[i] = rand()%1000;
    }
    display(a, n);
    t1 = time(NULL);
    quick_sort(a, 0, n-1);
    t2 = time(NULL);
    display(a, n);

    d = difftime(t2, t1);

    printf("Total time taken: %lf seconds.\n", d);

    return 0;
}