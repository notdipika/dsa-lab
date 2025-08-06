import math

def evaluate_postfix(expression):
    stack = []
    tokens = expression.strip().split()

    for token in tokens:
        if token.replace('.', '', 1).lstrip('-').isdigit():
            value = float(token)
            stack.append(value)
            print(f"{value:.2f} pushed to stack.")
        else:
            if len(stack) < 2:
                print("Error: Not enough operands.")
                exit(1)
            b = stack.pop()
            a = stack.pop()

            if token == '^':
                stack.append(math.pow(a, b))

            elif token == '/':
                if b == 0:
                    print("Division by zero error!")
                    exit(1)
                stack.append(a / b)  

            elif token == '*':
                stack.append(a * b)

            elif token == '+':
                stack.append(a + b)

            elif token == '-':
                stack.append(a - b)

            else:
                print(f"Unknown operator: {token}")
                exit(1)

    if len(stack) != 1:
        print("Error: Invalid postfix expression.")
        exit(1)

    result = stack.pop()
    print(f"Result: {result:.2f}")

if __name__ == "__main__":
    expression = input("Enter the postfix expression: ")
    evaluate_postfix(expression)
