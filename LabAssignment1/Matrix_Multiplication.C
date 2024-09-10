#include <stdio.h>

void multiplyMatrices(int a[][10], int b[][10], int result[][10], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("Error: Multiplication is not possible. The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return;
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Error: Multiplication is not possible. The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1;
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    multiplyMatrices(a, b, result, r1, c1, r2, c2);

    printf("MULTIPLICATION OF TWO 2D MATRICES IS:\n");
    printMatrix(result, r1, c2);

    return 0;
}