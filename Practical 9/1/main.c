#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/**
 * @brief Performs a linear search on an array to find the target value.
 *
 * @param arr The array to be searched.
 * @param size The size of the array.
 * @param target The target value to search for.
 *
 * @return int Returns the index of the target value if found, or -1 if not found.
 */
int linearSearch(int arr[], int size, int target)
{
  // Iterate through each element in the array.
  for (int i = 0; i < size; i++)
  {
    // If the current element is equal to the target value, return the index.
    if (arr[i] == target)
    {
      return i;
    }
  }
  // If the target value is not found in the array, return -1.
  return -1;
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
  // Variable to store the size of the array.
  int size;

  // Prompt the user to enter the size of the array.
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Dynamically allocate memory for the array of integers.
  int *arr = (int *)malloc(size * sizeof(int));

  // Check if memory allocation was successful.
  if (arr == NULL)
  {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Prompt the user to enter the elements of the array.
  printf("Enter the elements of the array:\n");
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }

  // Variable to store the target value to search for.
  int target;
  // Prompt the user to enter the target value.
  printf("Enter the target value to search for: ");
  scanf("%d", &target);

  // Perform a linear search to find the target value in the array.
  int index = linearSearch(arr, size, target);

  // Check if the target value was found in the array.
  if (index != -1)
  {
    // If found, print the index of the target value.
    printf("Target value %d found at index %d.\n", target, index);
  }
  else
  {
    // If not found, print a message indicating so.
    printf("Target value %d not found in the array.\n", target);
  }

  // Free the dynamically allocated memory for the array.
  free(arr);
  // Wait for a key press before exiting the program.
  getch();
  // Return 0 to indicate successful execution.
  return 0;
}