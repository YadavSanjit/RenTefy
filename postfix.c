#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_SIZE 100

int stack[MAX_SIZE]; // Global stack array
int top = -1;       // Global top index

// Push an item onto the stack
void push(int value) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Pop an item from the stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    printf("Stack underflow\n");
    return -1;
}

// Check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Evaluate postfix expression
int evaluatePostfix(char *exp) {
    int i = 0;
    while (exp[i] != '\0') {
        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If character is a digit
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        }
        // If character is an operator
        else {
            int val2 = pop();
            int val1 = pop();
            switch (exp[i]) {
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    if (val2 == 0) {
                        printf("Division by zero\n");
                        return -1;
                    }
                    push(val1 / val2);
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
            i++;
        }
    }
    return pop();
}

// Main function to test
int main() {
    char exp[] = "5 3 2 * +"; // Postfix expression: (5 + (3 * 2)) = 11
    int result = evaluatePostfix(exp);
    if (result != -1) {
        printf("Result of postfix expression %s is %d\n", exp, result);
    }
    return 0;
}