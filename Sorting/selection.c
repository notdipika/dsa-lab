#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 200000

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int a[], int n){
    for(int i=0; i<n; i++){
        int smallest = a[i];
        int pos = i;
        for(int j=i+1; j<n; j++){
            if(a[j] < smallest){
                smallest = a[j];
                pos = j;
            }
        }
        if(i!=pos){
            swap(&a[i], &a[pos]);
        }
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
    selection_sort(a, n);
    t2 = time(NULL);
    display(a, n);

    d = difftime(t2, t1);

    printf("Total time taken: %lf seconds.\n", d);

    return 0;
}