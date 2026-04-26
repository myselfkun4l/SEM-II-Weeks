#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int evaluatePostfix(char* postfix) {
    int i = 0;
    char c;
    int op1, op2;

    while ((c = postfix[i++]) != '\0') {
        if (isdigit(c)) {
            push(c - '0');
        } else {
            op2 = pop();
            op1 = pop();

            switch (c) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': {
                    int result = 1;
                    for (int j = 0; j < op2; j++) result *= op1;
                    push(result);
                    break;
                }
                default:
                    printf("Invalid operator: %c\n", c);
                    return -1;
            }
        }
    }
    return pop();
}

int main() {
    char postfix[MAX];
    printf("Enter Postfix Expression (single-digit operands): ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
