#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000


typedef struct 
{
    char data[MAX];
    int top;
}   Stack;

void init(Stack *s) 
{
    s->top = -1;
}

int isEmpty(Stack *s) 
{
    return s->top == -1;
}

void push(Stack *s, char item) 
{
    s->data[++(s->top)] = item;
}

char pop(Stack *s) 
{
    if (isEmpty(s)) return '\0';
    return s->data[(s->top)--];
}

char peek(Stack *s) 
{
    if (isEmpty(s)) return '\0';
    return s->data[s->top];
}

int precedence(char op) 
{
    switch (op) 
    {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isOperator(char ch) 
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(const char *infix, char *postfix) 
{
    Stack s;
    init(&s);
    int i = 0, k = 0;

    while (infix[i] != '\0')
     {
        if (isspace(infix[i])) 
        {
            i++;
            continue;
        }

        if (isalnum(infix[i])) 
        {
            while (isalnum(infix[i])) {
                postfix[k++] = infix[i++];
            }
            postfix[k++] = ' ';
        }

        else if (infix[i] == '(') 
        {
            push(&s, infix[i]);
            i++;
        }

        else if (infix[i] == ')')
         {
            while (!isEmpty(&s) && peek(&s) != '(') 
            {
                postfix[k++] = pop(&s);
                postfix[k++] = ' ';
            }
            if (!isEmpty(&s) && peek(&s) == '(') 
            {
                pop(&s); 
            }
            i++;
        }

        else if (isOperator(infix[i])) 
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i]) && peek(&s) != '(') 
            {
                postfix[k++] = pop(&s);
                postfix[k++] = ' ';
            }
            push(&s, infix[i]);
            i++;
        }

        else {
            printf("Invalid character: %c\n", infix[i]);
            return;
        }
    }

    while (!isEmpty(&s)) 
    {
        postfix[k++] = pop(&s);
        postfix[k++] = ' ';
    }

    postfix[k] = '\0';
}

int main() 
{
    char infix[MAX], postfix[MAX] = "";
    printf("Enter an infix expression:\n");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix expression:\n%s\n", postfix);
    return 0;
}
