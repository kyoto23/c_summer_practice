#include "functions.h"
#include <stdio.h>

int main() {
  int rows, cols, choice;

  printf("Введіть к-сть рядків та стовпчиків: ");
  scanf("%d %d", &rows, &cols);

  int matrix[rows][cols];

  printf("Введіть ел-нти матриці:\n");
  inputMatrix(matrix, rows, cols);

  printf("\nПочаткова матриця:\n");
  printMatrix(matrix, rows, cols);
  printf("\n");

  do {
    printf(
        "Введіть номер шуканого:\n1)Матриця відсортована за зростанням по "
        "рядках\n2)Матриця відсортована за зростанням по стовпчикам\n3)Матриця "
        "відсортована за спаданням по рядках\n4)Матриця відсортована за "
        "спаданням по стовпчикам\n5)Закрити програму\nНомер - ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      sortMatrixByRows(matrix, rows, cols, 1);
      printf("\n");
      break;
    case 2:
      sortMatrixByColumns(matrix, rows, cols, 1);
      printf("\n");
      break;
    case 3:
      sortMatrixByRows(matrix, rows, cols, 0);
      printf("\n");
      break;
    case 4:
      sortMatrixByColumns(matrix, rows, cols, 0);
      printf("\n");
      break;
    case 5:
      printf("Вихід з програми...");
      break;}
  } while (choice!=5);
  // printf("\nМатриця відсортована за зростанням по рядках:\n");
  // sortMatrixByRows(matrix, rows, cols, 1);
  // // printMatrix(matrix, rows, cols);

  // printf("\nМатриця відсортована за зростанням по стовпчикам:\n");
  // sortMatrixByColumns(matrix, rows, cols, 1);
  // // printMatrix(matrix, rows, cols);

  // printf("\nМатриця відсортована за спаданням по рядках:\n");
  // sortMatrixByRows(matrix, rows, cols, 0);
  // // printMatrix(matrix, rows, cols);

  // printf("\nМатриця відсортована за спаданням по стовпчикам:\n");
  // sortMatrixByColumns(matrix, rows, cols, 0);
  // // printMatrix(matrix, rows, cols);
  return 0;
}
