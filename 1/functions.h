#define MAX_ROWS 100
#define MAX_COLS 100

void inputMatrix(int matrix[][MAX_COLS], int rows, int cols);
void printMatrix(int matrix[][MAX_COLS], int rows, int cols);
void sortMatrixByRows(int matrix[][MAX_COLS], int rows, int cols, int ascending);
void sortMatrixByColumns(int matrix[][MAX_COLS], int rows, int cols, int ascending);