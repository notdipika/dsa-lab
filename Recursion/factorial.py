def tail_fact(n, a=1):
    if n == 0:
        return a
    else:
        return tail_fact(n - 1, a * n)

n = int(input("Enter a number: "))
print(f"Factorial of {n} is {tail_fact(n)}")
