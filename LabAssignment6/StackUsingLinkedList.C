#include <stdio.h>
#include <stdlib.h>

// Define a node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function Prototypes
void push(struct Node** top, int value);
void pop(struct Node** top);
int peek(struct Node* top);
void display(struct Node* top);

int main() {
    struct Node* top = NULL;  // Initialize the stack as empty (linked list)

    int choice, value;

    while (1) {
        // Menu options
        printf("\n--- Stack Menu (Using Linked List) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top Element)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Push
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;

            case 2: // Pop
                pop(&top);
                break;

            case 3: // Peek
                if (top == NULL)
                    printf("Stack is empty\n");
                else
                    printf("Top element is: %d\n", peek(top));
                break;

            case 4: // Display
                display(top);
                break;

            case 5: // Exit
                exit(0);

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }

    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! No elements to pop\n");
        return;
    }

    struct Node* temp = *top;
    printf("Popped element: %d\n", temp->data);
    *top = (*top)->next;
    free(temp);
}

// Function to peek the top element of the stack
int peek(struct Node* top) {
    return top->data;
}

// Function to display the elements of the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
