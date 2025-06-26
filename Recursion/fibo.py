MAX = 50
memo = [-1] * MAX

def memo_fibo(n):
    if n == 1 or n == 2:
        return 1
    if memo[n] != -1:
        return memo[n]
    memo[n] = memo_fibo(n - 1) + memo_fibo(n - 2)
    return memo[n]

n = int(input("Enter a number: "))
print(f"Fibonacci of {n} is {memo_fibo(n)}")
