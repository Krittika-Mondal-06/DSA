#include <stdio.h>
#include <ctype.h>  // For isdigit()
#include <string.h> // For string functions
#include <stdlib.h> // For exit()

#define MAX 100  // Maximum size of the stack

// Stack structure to store operands
struct Stack {
    int top;
    int items[MAX];
};

// Function prototypes
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);
int evaluatePrefix(char prefix[]);

int main() {
    char prefix[MAX];

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    int result = evaluatePrefix(prefix);
    printf("The result of the prefix expression is: %d\n", result);

    return 0;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    } else {
        stack->items[++(stack->top)] = value;
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    } else {
        return stack->items[(stack->top)--];
    }
}

// Function to evaluate a prefix expression
int evaluatePrefix(char prefix[]) {
    struct Stack stack;
    stack.top = -1;  // Initialize the stack

    int length = strlen(prefix);

    // Loop through the expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        char current = prefix[i];

        // If the character is an operand, push it to the stack
        if (isdigit(current)) {
            push(&stack, current - '0');  // Convert character to integer
        }
        // If the character is an operator, pop operands and apply the operator
        else {
            int operand1 = pop(&stack);  // Pop two operands
            int operand2 = pop(&stack);

            switch (current) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error!\n");
                        exit(1);
                    }
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator encountered!\n");
                    exit(1);
            }
        }
    }

    // The final result is the only element left in the stack
    return pop(&stack);
}
