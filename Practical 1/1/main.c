#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/**
 * @brief Resizes an array to a new size while preserving existing elements and initializing new elements to zero.
 *
 * @param array Pointer to the original array.
 * @param currentSize Current size of the array.
 * @param newSize New size to resize the array to.
 * @return Pointer to the resized array.
 *
 * @note If the memory allocation for the resized array fails, the program exits with an error message.
 * @note If the new size is greater than the current size, the new elements are initialized to zero.
 */
int *resizeArray(int *array, int currentSize, int newSize)
{
  // Reallocate memory for the array to resize it to the new size.
  int *resizedArray = (int *)realloc(array, newSize * sizeof(int));
  // Check if memory allocation failed.
  if (resizedArray == NULL)
  {
    printf("Memory allocation failed. Exiting...\n");
    exit(1);
  }

  // If the new size is greater than the current size, initialize the new elements to zero.
  if (newSize > currentSize)
  {
    for (int i = currentSize; i < newSize; ++i)
    {
      resizedArray[i] = 0;
    }
  }

  // Return the pointer to the resized array.
  return resizedArray;
}

/**
 * @brief Main function to initialize an array with user-provided elements, resize the array, and display the resized array.
 *
 * @return Integer value indicating the exit status of the program.
 *
 * @note The program prompts the user to enter the initial size of the array and its elements.
 * @note It then prompts the user to enter the new size of the array for resizing.
 * @note After resizing, it displays the original and resized arrays.
 * @note Memory allocated for the array is freed before exiting.
 */
int main(void)
{
  int size;
  // Prompt the user to enter the initial size of the array.
  printf("Enter the initial size of the array: ");
  // Read the initial size of the array from the user.
  scanf("%d", &size);

  // Allocate memory for the array based on the initial size.
  int *array = (int *)malloc(size * sizeof(int));
  // Check if memory allocation failed.
  if (array == NULL)
  {
    printf("Memory allocation failed. Exiting...\n");
    return 1;
  }

  // Prompt the user to enter the elements of the array.
  printf("Enter %d elements for the array:\n", size);
  // Read the elements of the array from the user.
  for (int i = 0; i < size; ++i)
  {
    scanf("%d", &array[i]);
  }

  // Display the original array.
  printf("Original array:\n");
  for (int i = 0; i < size; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  int newSize;
  // Prompt the user to enter the new size of the array.
  printf("Enter the new size of the array: ");
  // Read the new size of the array from the user.
  scanf("%d", &newSize);

  // Resize the array.
  array = resizeArray(array, size, newSize);
  size = newSize;

  // Display the resized array.
  printf("Array after resizing:\n");
  for (int i = 0; i < size; ++i)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  // Free the allocated memory for the array.
  free(array);

  // Wait for the user key press before exit
  getch();
  // Indicate successful execution of the program.
  return 0;
}
