#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/**
 * @brief Swaps the values of two integer pointers.
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
 * @brief Reverses the order of elements in an array.
 *
 * @param row The array to be reversed.
 * @param n The size of the array.
 *
 * @return void
 */
void reverseRow(int row[], int n)
{
  // Initialize pointers for the start and end of the array.
  int start = 0, end = n - 1;
  // Swap elements from the start and end of the array, working towards the center.
  while (start < end)
  {
    swap(&row[start], &row[end]);
    start++;
    end--;
  }
}

/**
 * @brief Sorts and then reverses each row of a matrix.
 *
 * @param matrix The matrix to be processed.
 * @param m The number of rows in the matrix.
 * @param n The number of columns in the matrix.
 *
 * @return void
 */
void sortAndReverseMatrix(int **matrix, int m, int n)
{
  // Iterate through each row of the matrix.
  for (int i = 0; i < m; i++)
  {
    // Sort the current row using bubble sort.
    bubbleSort(matrix[i], n);
    // Reverse the current row.
    reverseRow(matrix[i], n);
  }
}

/**
 * @brief Prints a matrix to the console.
 *
 * @param matrix The matrix to be printed.
 * @param m The number of rows in the matrix.
 * @param n The number of columns in the matrix.
 *
 * @return void
 */
void printMatrix(int **matrix, int m, int n)
{
  // Iterate through each row of the matrix.
  for (int i = 0; i < m; i++)
  {
    // Print each element of the row.
    for (int j = 0; j < n; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    // Print a newline after each row.
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
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }

  // Sort each row and then reverse it.
  sortAndReverseMatrix(matrix, m, n);

  // Print the sorted and reversed matrix.
  printf("Sorted and reversed matrix:\n");
  printMatrix(matrix, m, n);

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