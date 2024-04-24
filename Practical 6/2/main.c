#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/**
 * @brief Swaps the values of two integers using pointers.
 *
 * @param a Pointer to the first integer to be swapped.
 * @param b Pointer to the second integer to be swapped.
 */
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

/**
 * @brief Sorts an array using the bubble sort algorithm.
 *
 * The function takes an array and its size as parameters and sorts the array
 * using the bubble sort algorithm.
 *
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void bubbleSort(int arr[], int n)
{
  int i, j;

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

/**
 * @brief Main function that prompts the user to input an array of integers,
 * sorts the array, and performs calculations on the sorted array.
 *
 * @return int Returns 0 upon successful execution.
 */
int main(void)
{
  int n;

  printf("Enter the number of integers: ");
  scanf("%d", &n);

  // Allocate memory for the array of size n
  int *arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL)
  {
    printf("Memory allocation failed.\n");
    return 1;
  }

  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  // Sort the array
  bubbleSort(arr, n);

  // Calculate the product of elements at odd positions (0, 2, 4, ...)
  long int productOdd = 1;
  for (int i = 0; i < n; i += 2)
  {
    productOdd *= arr[i];
  }
  printf("Product of elements at odd positions: %ld\n", productOdd);

  // Calculate the sum of elements at even positions (1, 3, 5, ...)
  long int sumEven = 0;
  for (int i = 1; i < n; i += 2)
  {
    sumEven += arr[i];
  }
  printf("Sum of elements at even positions: %ld\n", sumEven);

  // Free the allocated memory
  free(arr);

  // Wait for the key press before exiting
  getch();
  return 0;
}