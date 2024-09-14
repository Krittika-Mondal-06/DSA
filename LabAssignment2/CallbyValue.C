#include <stdio.h>

void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2;}
    printf("Array elements inside the function:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);}
    printf("\n");}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array elements before function call:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);}
    printf("\n");
    modifyArray(arr, size);
    printf("Array elements after function call:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);}
    printf("\n");
    return 0;
}