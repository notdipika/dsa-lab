#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 5


typedef struct{
    float data[MAX];
    int top;
}Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, float value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->data[++(s->top)] = value;
    printf("%d pushed to stack.\n", value);
}


float pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    return s->data[(s->top)--];
}


int main() {
    float value, result;
    Stack s;
    init(&s);
    char exp[100];  
    printf("Enter the expression: ");
    fgets(exp, 100, stdin);
    printf("Scanned expression: %s", exp);
    char *token = strtok(exp, " ");
    while (token != NULL) {    
    
        if (isdigit(token[0])) {
            push(&s, atof(token));
        }  
        else {
           float b = pop(&s);
           float a = pop(&s);
            switch (token[0]) {
                case '+': 
                push(&s, a + b); 
                break;
                case '-': 
                push(&s, a - b); 
                break;
                case '*': 
                push(&s, a * b); 
                break;
                case '/': 
                push(&s, a / b); 
                break;
            }
        }
    }
    return pop(&s);
}