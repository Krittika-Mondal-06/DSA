#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the circular queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to insert an element into the circular queue (Enqueue)
void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full. Overflow condition!\n");
        return;
    }
    if (front == -1) { // Insert the first element
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0; // Wrap around to the beginning
    } else {
        rear++;
    }
    queue[rear] = element;
    printf("%d inserted into the queue.\n", element);
}

// Function to delete an element from the circular queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Underflow condition!\n");
        return;
    }
    printf("%d deleted from the queue.\n", queue[front]);
    
    if (front == rear) { // Only one element in the queue
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0; // Wrap around to the beginning
    } else {
        front++;
    }
}

// Function to return the front element of the circular queue (Peep)
void peep() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element is %d.\n", queue[front]);
}

// Function to display all elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

// Main function with a menu to select queue operations
int main() {
    int choice, element;

    while (1) {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peep (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peep();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
