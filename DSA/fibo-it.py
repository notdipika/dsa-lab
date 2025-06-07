import time

def fibonacci_iterative(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
    return a

# Input
n = int(input("Enter the value of n: "))

start = time.time()
result = fibonacci_iterative(n)
end = time.time()

print(f"The {n}th Fibonacci number is: {result}")
print(f"Time taken: {end - start:.20f} seconds")
