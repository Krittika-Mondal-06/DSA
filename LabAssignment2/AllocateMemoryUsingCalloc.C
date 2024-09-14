#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, *temp_ptr, n1, n2, i;

    // Allocate initial memory using calloc
    printf("Enter the number of elements: ");
    scanf("%d", &n1);

    ptr = (int *)calloc(n1, sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &ptr[i]);
    }

    // Reallocate memory using realloc
    printf("Enter the new number of elements: ");
    scanf("%d", &n2);

    temp_ptr = (int *)realloc(ptr, n2 * sizeof(int));

    if (temp_ptr == NULL) {
        printf("Memory reallocation failed.\n");
        free(ptr);
        return 1;
    }

    ptr = temp_ptr; // Update the pointer

    // Display elements after reallocation
    printf("Elements after reallocation:\n");
    for (i = 0; i < n2; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
    return 0;
}