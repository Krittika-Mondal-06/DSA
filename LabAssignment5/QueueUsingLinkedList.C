#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Function to initialize a queue
void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Function to insert an element into the queue (Enqueue)
void enqueue(struct Queue* q, int value) {
    struct Node* temp = createNode(value);

    if (q->rear == NULL) { // Queue is empty
        q->front = q->rear = temp;
        printf("%d inserted into the queue.\n", value);
        return;
    }

    q->rear->next = temp; // Link the new node to the last node
    q->rear = temp;       // Update rear
    printf("%d inserted into the queue.\n", value);
}

// Function to delete an element from the queue (Dequeue)
void dequeue(struct Queue* q) {
    if (q->front == NULL) { // Queue is empty
        printf("Queue is empty. Underflow condition!\n");
        return;
    }

    struct Node* temp = q->front;
    printf("%d deleted from the queue.\n", temp->data);

    q->front = q->front->next; // Move front to the next node

    if (q->front == NULL) { // If the queue is empty after dequeue
        q->rear = NULL;
    }

    free(temp); // Free the dequeued node
}

// Function to return the front element of the queue (Peep)
void peep(struct Queue* q) {
    if (q->front == NULL) { // Queue is empty
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element is %d.\n", q->front->data);
}

// Function to display all elements of the queue
void display(struct Queue* q) {
    if (q->front == NULL) { // Queue is empty
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with a menu to select queue operations
int main() {
    struct Queue q;
    initializeQueue(&q);

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
                enqueue(&q, element);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peep(&q);
                break;
            case 4:
                display(&q);
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
