#include <stdio.h>
#define MAX 5 // Maximum queue size

int q[MAX]; // Queue array
int front = -1, rear = -1; // Front and rear pointers

// Check if queue is empty
int empty() {
    if (front == -1 || front > rear) {
        return 1; // True
    }
    return 0; // False
}

// Check if queue is full
int full() {
    if (rear == MAX - 1) {
        return 1; // True
    }
    return 0; // False
}

// Enqueue operation
void inq(int item) {
    if (full()) {
        printf("Queue is full.\n");
        return;
    }
    if (empty()) {
        front = 0; // Initialize front for the first element
    }
    rear++;
    q[rear] = item;
    printf("Enqueued %d\n", item);
}

// Dequeue operation
int Dq() {
    if (empty()) {
        printf("Queue is empty.\n");
        return -1; // Indicate failure
    }
    int itm = q[front];
    front++;
    if (front > rear) { // Reset queue when empty
        front = -1;
        rear = -1;
    }
    return itm;
}

int main() {
    int choice, item;
    while (1) {
        printf("\nSelect operation:\n1. Add element\n2. Delete element\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Enqueue
                printf("Enter element to add: ");
                scanf("%d", &item);
                inq(item);
                break;
            case 2: // Dequeue
                item = Dq();
                if (item != -1) {
                    printf("Dequeued %d\n", item);
                }
                break;
            case 3: // Exit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}