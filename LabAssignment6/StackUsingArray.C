#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the stack

// Function Prototypes
void push(int stack[], int *top, int value);
void pop(int stack[], int *top);
int peek(int stack[], int top);
void display(int stack[], int top);

int main() {
    int stack[MAX];
    int top = -1;  // Initialize the stack as empty
    int choice, value;

    while (1) {
        // Menu options
        printf("\n--- Stack Menu (Using Array) ---\n");
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
                push(stack, &top, value);
                break;

            case 2: // Pop
                pop(stack, &top);
                break;

            case 3: // Peek
                if (top == -1)
                    printf("Stack is empty\n");
                else
                    printf("Top element is: %d\n", peek(stack, top));
                break;

            case 4: // Display
                display(stack, top);
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
void push(int stack[], int *top, int value) {
    if (*top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        (*top)++;
        stack[*top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Function to pop an element from the stack
void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow! No elements to pop\n");
    } else {
        printf("Popped element: %d\n", stack[*top]);
        (*top)--;
    }
}

// Function to peek the top element of the stack
int peek(int stack[], int top) {
    return stack[top];
}

// Function to display the elements of the stack
void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
