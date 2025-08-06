#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 2000

void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void display(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
}

int main()
{
    int i, a[MAX], n;
    srand(time(NULL));
    time_t t1, t2;
    double d;
    printf("Enter n:");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        a[i] = rand()%1000;
    }
    display(a,n);
    t1= time(NULL);
    bubble_sort(a,n);
    t2= time(NULL);
    display(a,n);
    d = difftime(t1,t2);
    printf("The time is %lf seconds.", d);
    return 0;
}