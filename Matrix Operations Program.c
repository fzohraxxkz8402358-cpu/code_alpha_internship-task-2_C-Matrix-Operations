/*
 * Matrix Operations Program
 * Implements: Addition, Multiplication, Transpose
 * Uses functions and 2D arrays for modularity
 */

#include <stdio.h>

#define MAX 10

/* ---------- Function declarations ---------- */
void inputMatrix(int m[][MAX], int rows, int cols, const char *label);
void displayMatrix(int m[][MAX], int rows, int cols, const char *label);
void addMatrices(int a[][MAX], int b[][MAX], int result[][MAX], int rows, int cols);
void multiplyMatrices(int a[][MAX], int b[][MAX], int result[][MAX],
                       int rowsA, int colsA, int colsB);
void transposeMatrix(int m[][MAX], int result[][MAX], int rows, int cols);

/* ---------- Function definitions ---------- */

void inputMatrix(int m[][MAX], int rows, int cols, const char *label) {
    printf("\nEnter elements for matrix %s (%d x %d):\n", label, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void displayMatrix(int m[][MAX], int rows, int cols, const char *label) {
    printf("\nMatrix %s:\n", label);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[][MAX], int b[][MAX], int result[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[][MAX], int b[][MAX], int result[][MAX],
                       int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int m[][MAX], int result[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = m[i][j];
        }
    }
}

int main() {
    int choice;
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    while (1) {
        printf("\n===== Matrix Operations =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1: {
                printf("Enter rows and columns (both matrices must match): ");
                scanf("%d %d", &rowsA, &colsA);
                if (rowsA <= 0 || colsA <= 0 || rowsA > MAX || colsA > MAX) {
                    printf("Invalid size. Must be between 1 and %d.\n", MAX);
                    break;
                }
                inputMatrix(a, rowsA, colsA, "A");
                inputMatrix(b, rowsA, colsA, "B");
                addMatrices(a, b, result, rowsA, colsA);
                displayMatrix(result, rowsA, colsA, "Result (A + B)");
                break;
            }
            case 2: {
                printf("Enter rows and columns of matrix A: ");
                scanf("%d %d", &rowsA, &colsA);
                printf("Enter rows and columns of matrix B: ");
                scanf("%d %d", &rowsB, &colsB);

                if (rowsA <= 0 || colsA <= 0 || rowsB <= 0 || colsB <= 0 ||
                    rowsA > MAX || colsA > MAX || rowsB > MAX || colsB > MAX) {
                    printf("Invalid size. Must be between 1 and %d.\n", MAX);
                    break;
                }
                if (colsA != rowsB) {
                    printf("Error: Cannot multiply. Columns of A (%d) must equal rows of B (%d).\n",
                           colsA, rowsB);
                    break;
                }
                inputMatrix(a, rowsA, colsA, "A");
                inputMatrix(b, rowsB, colsB, "B");
                multiplyMatrices(a, b, result, rowsA, colsA, colsB);
                displayMatrix(result, rowsA, colsB, "Result (A x B)");
                break;
            }
            case 3: {
                printf("Enter rows and columns of the matrix: ");
                scanf("%d %d", &rowsA, &colsA);
                if (rowsA <= 0 || colsA <= 0 || rowsA > MAX || colsA > MAX) {
                    printf("Invalid size. Must be between 1 and %d.\n", MAX);
                    break;
                }
                inputMatrix(a, rowsA, colsA, "A");
                transposeMatrix(a, result, rowsA, colsA);
                displayMatrix(result, colsA, rowsA, "Transpose of A");
                break;
            }
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select between 1 and 4.\n");
        }
    }

    return 0;
}
