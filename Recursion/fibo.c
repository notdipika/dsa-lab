#include<stdio.h>
#define MAX 50

int memo[MAX];


int memoFibo(int n) 
{
    if (n == 1 || n ==2 )
        return 1;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = memoFibo(n - 1) + memoFibo(n - 2);
    return memo[n];
}

int main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) 
    {
        memo[i] = -1; 
    }
    printf("Fibonacci of %d is %d\n", n, memoFibo(n));
    return 0;
}




