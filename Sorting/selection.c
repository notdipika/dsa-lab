#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 200000

void selection_sort(int a[], int n)
{
    int i, j, temp, least, pos;
    for (i = 0; i < n; i++)
    {
        least = a[i];
        pos = i;
        for(j = i + 1; j < n; j++)
        {
            if(a[j]<least)
            {
                least = a[j];
                pos = j;
            }
        }
        if (i != pos)
        {
            temp = a[i];
            a[i] = a[pos];
            a[pos]=temp;
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
        a[i] = rand()%100;
    }
    display(a,n);
    t1= time(NULL);
    selection_sort(a,n);
    t2= time(NULL);
    display(a,n);
    d = difftime(t2,t1);
    printf("The time is %lf seconds.", d);
    return 0;
}