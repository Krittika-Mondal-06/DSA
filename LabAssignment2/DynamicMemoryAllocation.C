#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, search, found = 0;
    int *arr;

    // Get the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input elements
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to be searched
    printf("Enter the element to search: ");
    scanf("%d", &search);

    // Search for the element
    for (i = 0; i < n; i++) {
        if (arr[i] == search) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Element found at index %d\n", i);
    } else {
        printf("Element not found\n");
    }

    // Free the allocated memory
    free(arr);

    return 0;
}