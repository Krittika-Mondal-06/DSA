#include <stdio.h>

// Function to solve Tower of Hanoi problem recursively
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        // Base case: Only one disk, move it directly from source to destination
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }

    // Recursive case:
    
    // Step 1: Move the top n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Step 2: Move the nth disk from source to destination
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    
    // Step 3: Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // A is the source rod, C is the destination rod, B is the auxiliary rod
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}
