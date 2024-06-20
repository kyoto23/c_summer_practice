#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int matrix[][MAX_COLS], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      scanf("%d", &matrix[i][j]);
  }
}

void printMatrix(int matrix[][MAX_COLS], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      printf("%d ", matrix[i][j]);
    printf("\n");
  }
}

void sortMatrixByRows(int matrix[][MAX_COLS], int rows, int cols,
                      int ascending) {
  int temp[MAX_COLS];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols - 1; j++) {
      for (int k = 0; k < cols - j - 1; k++) {
        if ((ascending && matrix[i][k] > matrix[i][k + 1]) ||
            (!ascending && matrix[i][k] < matrix[i][k + 1])) {
          // Swap elements
          temp[k] = matrix[i][k];
          matrix[i][k] = matrix[i][k + 1];
          matrix[i][k + 1] = temp[k];
        }
      }
    }
  }
  printMatrix(matrix, rows, cols);
}

void sortMatrixByColumns(int matrix[][MAX_COLS], int rows, int cols,
                         int ascending) {
  int temp[MAX_ROWS];

  for (int j = 0; j < cols; j++) {
    for (int i = 0; i < rows - 1; i++) {
      for (int k = 0; k < rows - i - 1; k++) {
        if ((ascending && matrix[k][j] > matrix[k + 1][j]) ||
            (!ascending && matrix[k][j] < matrix[k + 1][j])) {
          // Swap elements
          temp[k] = matrix[k][j];
          matrix[k][j] = matrix[k + 1][j];
          matrix[k + 1][j] = temp[k];
        }
      }
    }
  }
  printMatrix(matrix, rows, cols);
}