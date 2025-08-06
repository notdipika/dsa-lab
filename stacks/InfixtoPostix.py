def precedence(op):
    if op == '^':
        return 3
    elif op in ('*', '/'):
        return 2
    elif op in ('+', '-'):
        return 1
    return 0

def is_operator(ch):
    return ch in '+-*/^'

def infix_to_postfix(infix):
    stack = []
    postfix = []
    i = 0
    n = len(infix)

    while i < n:
        ch = infix[i]

        if ch.isspace():
            i += 1
            continue

        if ch.isalnum():
            operand = ''
            while i < n and infix[i].isalnum():
                operand += infix[i]
                i += 1
            postfix.append(operand)

        elif ch == '(':
            stack.append(ch)
            i += 1

        elif ch == ')':
            while stack and stack[-1] != '(':
                postfix.append(stack.pop())
            if stack and stack[-1] == '(':
                stack.pop()
            i += 1

        elif is_operator(ch):
            while stack and stack[-1] != '(' and precedence(stack[-1]) >= precedence(ch):
                postfix.append(stack.pop())
            stack.append(ch)
            i += 1
            
        else:
            print(f"Invalid character: {ch}")
            return ""

    while stack:
        postfix.append(stack.pop())

    return ' '.join(postfix)

if __name__ == "__main__":
    expr = input("Enter an infix expression:\n")
    result = infix_to_postfix(expr)
    print("Postfix expression:")
    print(result)
