#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void push(char c) {
    if (top < MAX_SIZE - 1) stack[++top] = c;
}

char pop() {
    if (top >= 0) return stack[top--];
    return '\0';
}

bool isEmpty() {
    return top == -1;
}

void infixToPostfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (infix[i] == ' ') {
            i++;
            continue;
        }
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9')) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty() && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty()) pop(); // Discard '('
        } else { // Operator
            while (!isEmpty() && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[] = "a + b * c";
    char postfix[MAX_SIZE];
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix); // Output: abc*+
    return 0;
}