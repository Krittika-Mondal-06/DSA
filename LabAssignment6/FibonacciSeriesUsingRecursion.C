#include <stdio.h>

// Function to calculate Fibonacci number using recursion
int fibonacci(int n) {
    if (n == 0) {
        return 0;  // Base case: F(0) = 0
    } else if (n == 1) {
        return 1;  // Base case: F(1) = 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case
    }
}

int main() {
    int n, i;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci series: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
    return 0;
}
