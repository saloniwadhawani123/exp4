
#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the circular queue

int queue[MAX];  // Array to store queue elements
int front = -1, rear = -1;  // Track the front and rear of the queue

// Function to check if the queue is full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element into the queue (enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue.\n");
    } else {
        if (front == -1) {  // If inserting the first element
            front = 0;
        }
        rear = (rear + 1) % MAX;  // Circular increment of rear
        queue[rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

// Function to remove an element from the queue (dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        printf("%d dequeued from the queue.\n", queue[front]);
        if (front == rear) {  // If the queue becomes empty after dequeue
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;  // Circular increment of front
        }
    }
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;  // Circular increment
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n*** Circular Queue Menu ***\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
