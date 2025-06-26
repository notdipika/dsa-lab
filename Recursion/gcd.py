def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

a, b = map(int, input("Enter two numbers: ").split())
print(f"GCD of {a} and {b} is {gcd(a, b)}")
