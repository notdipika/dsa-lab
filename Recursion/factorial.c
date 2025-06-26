#include<stdio.h>

long int tailFact(int n, long int a)
{
    if (n == 0)
        return a;
    else
    {
        return tailFact(n - 1, a * n);
    }
    
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %ld\n", n, tailFact(n, 1));
    return 0;
}