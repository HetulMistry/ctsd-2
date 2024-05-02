#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/**
 * @brief Swaps the values of two integers using pointers.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 *
 * @return void
 */
void swap(int *a, int *b)
{
  // Temporarily store the value of *a.
  int temp = *a;
  // Set *a to the value of *b.
  *a = *b;
  // Set *b to the value stored in temp.
  *b = temp;
}

/**
 * @brief Sorts an array in ascending order using the bubble sort algorithm.
 *
 * @param row The array to be sorted.
 * @param n The size of the array.
 *
 * @return void
 */
void bubbleSort(int row[], int n)
{
  // Perform bubble sort by iterating through the array.
  for (int i = 0; i < n - 1; i++)
  {
    // Loop through the array from the start to n - i - 1.
    for (int j = 0; j < n - i - 1; j++)
    {
      // If the current element is greater than the next, swap them.
      if (row[j] > row[j + 1])
      {
        swap(&row[j], &row[j + 1]);
      }
    }
  }
}

/**
 * @brief Sorts each row of a matrix in ascending order using the bubble sort algorithm.
 *
 * @param matrix The matrix to be sorted row-wise.
 * @param m The number of rows in the matrix.
 * @param n The number of columns in the matrix.
 *
 * @return void
 */
void sortMatrixRowWise(int **matrix, int m, int n)
{
  // Iterate through each row of the matrix.
  for (int i = 0; i < m; i++)
  {
    // Sort the current row using bubble sort.
    bubbleSort(matrix[i], n);
  }
}

/**
 * @brief Prints the elements of a matrix in column-major order.
 *
 * @param matrix The matrix to be printed.
 * @param m The number of rows in the matrix.
 * @param n The number of columns in the matrix.
 *
 * @return void
 */
void printMatrixColumnMajorOrder(int **matrix, int m, int n)
{
  // Iterate through each column of the matrix.
  for (int j = 0; j < n; j++)
  {
    // Iterate through each row of the matrix.
    for (int i = 0; i < m; i++)
    {
      // Print the current element, followed by a space.
      printf("%d ", matrix[i][j]);
    }
    // Print a newline after each column is printed.
    printf("\n");
  }
}

/**
 * @brief Entry point of the program.
 *
 * @param void
 *
 * @return int Returns 0 upon successful execution, or 1 if memory allocation fails.
 */
int main(void)
{
  // Variables to store the number of rows and columns of the matrix.
  int m, n;

  // Prompt the user to enter the number of rows in the matrix.
  printf("Enter the number of rows (m): ");
  scanf("%d", &m);

  // Prompt the user to enter the number of columns in the matrix.
  printf("Enter the number of columns (n): ");
  scanf("%d", &n);

  // Dynamically allocate memory for the matrix (array of pointers to integer arrays).
  int **matrix = (int **)malloc(m * sizeof(int *));

  // Allocate memory for each row of the matrix.
  for (int i = 0; i < m; i++)
  {
    matrix[i] = (int *)malloc(n * sizeof(int));
  }

  // Check if memory allocation failed.
  if (matrix == NULL)
  {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Prompt the user to enter the elements of the matrix.
  printf("Enter the elements of the matrix (%d rows, %d columns):\n", m, n);
  // Iterate through each row and each column to input the matrix elements.
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // Read the input value for the current element of the matrix.
      scanf("%d", &matrix[i][j]);
    }
  }

  // Sort each row of the matrix using bubble sort.
  sortMatrixRowWise(matrix, m, n);

  // Print the matrix elements in column-major order.
  printf("Matrix elements in column-major order:\n");
  printMatrixColumnMajorOrder(matrix, m, n);

  // Free the dynamically allocated memory for each row of the matrix.
  for (int i = 0; i < m; i++)
  {
    free(matrix[i]);
  }

  // Free the dynamically allocated memory for the matrix itself.
  free(matrix);
  // Wait for a key press before exiting the program.
  getch();
  // Return 0 to indicate successful execution.
  return 0;
}