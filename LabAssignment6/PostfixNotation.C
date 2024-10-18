#include <stdio.h>
#include <ctype.h>  // For isdigit() and isalpha()
#include <stdlib.h> // For exit()
#include <string.h>

#define MAX 100 // Maximum size of the stack

// Stack structure to store operators
struct Stack {
    int top;
    char items[MAX];
};

// Function prototypes
void push(struct Stack* stack, char value);
char pop(struct Stack* stack);
char peek(struct Stack* stack);
int isEmpty(struct Stack* stack);
int precedence(char op);
int isOperator(char ch);
void infixToPostfix(char infix[], char postfix[]);

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    } else {
        stack->items[++(stack->top)] = value;
    }
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    } else {
        return stack->items[(stack->top)--];
    }
}

// Function to peek the top element of the stack
char peek(struct Stack* stack) {
    if (stack->top == -1) {
        return '\0';
    }
    return stack->items[stack->top];
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    stack.top = -1;  // Initialize the stack
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char current = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(current)) {
            postfix[j++] = current;
        }
        // If the character is '(', push it to the stack
        else if (current == '(') {
            push(&stack, current);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (current == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) == '(') {
                pop(&stack);  // Remove the '(' from the stack
            }
        }
        // If the character is an operator
        else if (isOperator(current)) {
            while (!isEmpty(&stack) && precedence(current) <= precedence(peek(&stack))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, current);
        }

        i++;
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}
