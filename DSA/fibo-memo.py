import time

def fibonacci_memo(n, memo={}):
    if n in memo:
        return memo[n]
    if n <= 1:
        return n
    memo[n] = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo)
    return memo[n]

n = int(input("Enter the value of n: "))

start = time.time()
result = fibonacci_memo(n, {})
end = time.time()

print(f"The {n}th Fibonacci number is: {result}")
print(f"Time taken: {end - start:.10f} seconds")
