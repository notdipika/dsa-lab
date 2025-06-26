#include<stdio.h>

int moves = 0;

void TOH(int n, int src, int dest, int temp)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %d to rod %d\n", src, dest);
        moves++;
    }
    else 
    {
        TOH(n-1, src,temp,dest);
        printf("Move disk %d from rod %d to rod %d\n", n, src, dest);
        moves++;
        TOH(n-1, temp, dest, src);  
    }
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The sequence of moves are:\n");
    TOH(n, 1, 3, 2);
    printf("Total moves: %d\n", moves);
    return 0;
}