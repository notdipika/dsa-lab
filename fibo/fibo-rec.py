import time

def fibonacci_recursive(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

# Input
n = int(input("Enter the value of n: "))

start = time.time()
result = fibonacci_recursive(n)
end = time.time()

print(f"The {n}th Fibonacci number is: {result}")
print(f"Time taken: {end - start:.10f} seconds")
