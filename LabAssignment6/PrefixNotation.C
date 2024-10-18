#include <stdio.h>
#include <ctype.h>  // For isdigit() and isalpha()
#include <stdlib.h> // For exit()
#include <string.h>

#define MAX 100  // Maximum size of the stack

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
void reverseString(char* exp);
void infixToPrefix(char infix[], char prefix[]);
void infixToPostfix(char infix[], char postfix[]);  // Helper to convert modified infix to postfix

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

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

// Function to reverse a string
void reverseString(char* exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Function to convert infix expression to prefix
void infixToPrefix(char infix[], char prefix[]) {
    // Step 1: Reverse the infix expression
    reverseString(infix);

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Step 3: Get postfix of the modified infix
    char postfix[MAX];
    infixToPostfix(infix, postfix);

    // Step 4: Reverse the postfix expression to get prefix
    reverseString(postfix);
    strcpy(prefix, postfix);
}

// Helper function to convert infix expression to postfix (used by infixToPrefix)
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
