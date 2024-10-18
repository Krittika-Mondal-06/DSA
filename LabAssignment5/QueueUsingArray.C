#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Function to insert an element into the queue (Enqueue)
void enqueue(int element) {
    if (rear == MAX - 1) {
        printf("Queue is full. Overflow condition!\n");
        return;
    }
    if (front == -1) {
        front = 0; // Initialize front when inserting the first element
    }
    rear++;
    queue[rear] = element;
    printf("%d inserted into the queue.\n", element);
}

// Function to delete an element from the queue (Dequeue)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Underflow condition!\n");
        return;
    }
    printf("%d deleted from the queue.\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1; // Reset the queue when empty
    }
}

// Function to return the front element of the queue (Peep)
void peep() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element is %d.\n", queue[front]);
}

// Function to display all elements of the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function with a menu to select queue operations
int main() {
    int choice, element;

    while (1) {
        printf("\nQueue Operations Menu:\n");
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
