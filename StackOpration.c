#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100 // Maximum stack size

int items[MAX_SIZE]; // Global array for stack
int top = -1; // Global variable to track top of stack

// Check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Check if stack is full
bool isFull() {
    return top == MAX_SIZE - 1;
}

// Push an item to the stack
void push(int item) {
    if (isFull()) {
        printf("Stack is full\n");
        return;
    }
    items[++top] = item;
    printf("Pushed %d to stack\n", item);
}

// Pop an item from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1; // Error code
    }
    return items[top--];
}

// Peek at the top item
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1; // Error code
    }
    return items[top];
}

// Get stack size
int size() {
    return top + 1;
}

// Display stack contents
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", items[i]);
    }
    printf("\n");
}

// Main function to test the stack
int main() {
    // Test push operation
    push(1);
    push(2);
    push(3);
    display(); // Stack contents: 3 2 1

    // Test peek operation
    printf("Top item: %d\n", peek()); // Top item: 3

    // Test pop operation
    printf("Popped item: %d\n", pop()); // Popped item: 3
    display(); // Stack contents: 2 1

    // Test size operation
    printf("Stack size: %d\n", size()); // Stack size: 2

    // Test is_empty operation
    printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No"); // Is stack empty? No

    // Pop remaining items
    printf("Popped item: %d\n", pop()); // Popped item: 2
    printf("Popped item: %d\n", pop()); // Popped item: 1
    printf("Popped item: %d\n", pop()); // Stack is empty

    // Test empty stack
    printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No"); // Is stack empty? Yes
    display(); // Stack is empty

    return 0;
}
