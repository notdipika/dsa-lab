#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

typedef struct 
{
    float data[MAX];
    int top;
} Stack;

void init(Stack *s) 
{
    s->top = -1;
}

void push(Stack *s, float value) 
{
    if (s->top == MAX - 1) {
        printf("Stack Overflow! Cannot push %.2f\n", value);
        return;
    }

    s->data[++(s->top)] = value;
    printf("%.2f pushed to stack.\n", value);
}

float pop(Stack *s) 
{
    if (s->top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        exit(1);
    }
    
    return s->data[(s->top)--];
}

int main() 
{
    Stack s;
    init(&s);
    char exp[100];
    printf("Enter the postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " ");
    while (token != NULL) 
    {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) 
            push(&s, atof(token));

        else 
        {
            float b = pop(&s);
            float a = pop(&s);
            switch (token[0]) 

            {   
                case '^':
                push(&s, pow(a, b));
                break;

                case '/':
                if (b == 0) 
                {
                    printf("Division by zero error!\n");
                    exit(1);
                }
                push(&s, a / b);
                break;

                case '*': 
                push(&s, a * b); 
                break;

                case '+': 
                push(&s, a + b); 
                break;

                case '-': 
                push(&s, a - b); 
                break;

                default:
                    printf("Unknown operator: %s\n", token);
                    exit(1);

            }
        }
        token = strtok(NULL, " ");
    }

    float result = pop(&s);
    printf("Result: %.2f\n", result);
    return 0;
}
