#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10 // Maximum queue size

int queue[MAX_SIZE]; // Global array for queue
int front = -1;      // Front index, -1 indicates empty queue
int rear = -1;       // Rear index

// Check if queue is empty
bool isEmpty() {
    return front == -1;
}

// Check if queue is full
bool isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Enqueue (Add an element to the rear)
void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = item;
    printf("Enqueued %d\n", item);
}

// Dequeue (Remove an element from the front)
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1; // Error code
    }
    int item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("Dequeued %d\n", item);
    return item;
}

// Peek (View the front element)
int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1; // Error code
    }
    return queue[front];
}

// Get queue size
int size() {
    if (isEmpty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX_SIZE - front + rear + 1;
}

// Display queue contents
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents (front to rear): ");
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (front % MAX_SIZE));
    printf("\n");
}

// Main function to test the circular queue
int main() {
    // Test enqueue operation
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display(); // Queue contents: 1 2 3

    // Test peek operation
    printf("Front item: %d\n", peek()); // Front item: 1

    // Test dequeue operation
    printf("Dequeued item: %d\n", dequeue()); // Dequeued item: 1
    display(); // Queue contents: 2 3

    // Test size operation
    printf("Queue size: %d\n", size()); // Queue size: 2

    // Test isEmpty operation
    printf("Is queue empty? %s\n", isEmpty() ? "Yes" : "No"); // Is queue empty? No

    // Enqueue to demonstrate circular behavior
    enqueue(4);
    enqueue(5);
    printf("Dequeued item: %d\n", dequeue()); // Dequeued item: 2
    enqueue(6); // Should wrap around
    display(); // Queue contents: 3 4 5 6

    // Dequeue remaining items
    printf("Dequeued item: %d\n", dequeue()); // Dequeued item: 3
    printf("Dequeued item: %d\n", dequeue()); // Dequeued item: 4
    printf("Dequeued item: %d\n", dequeue()); // Dequeued item: 5
    printf("Dequeued item: %d\n", dequeue()); // Dequeued item: 6
    printf("Dequeued item: %d\n", dequeue()); // Queue is empty

    // Test empty queue
    printf("Is queue empty? %s\n", isEmpty() ? "Yes" : "No"); // Is queue empty? Yes
    display(); // Queue is empty

    return 0;
}