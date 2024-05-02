#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/**
 * @brief Performs a binary search on a sorted array to find the target value.
 *
 * @param arr The sorted array to be searched.
 * @param left The starting index of the search range.
 * @param right The ending index of the search range.
 * @param target The target value to search for.
 *
 * @return int Returns the index of the target value if found, or -1 if not found.
 */
int binarySearch(int arr[], int left, int right, int target)
{
  // Continue the search while the range is valid (left <= right).
  while (left <= right)
  {
    // Calculate the middle index of the range.
    int mid = left + (right - left) / 2;

    // Check if the middle element is equal to the target value.
    if (arr[mid] == target)
    {
      // If found, return the index of the middle element.
      return mid;
    }

    // If the middle element is greater than the target, adjust the search range to the left half.
    if (arr[mid] > target)
    {
      right = mid - 1;
    }
    // If the middle element is less than the target, adjust the search range to the right half.
    else
    {
      left = mid + 1;
    }
  }

  // If the target value is not found in the range, return -1.
  return -1;
}

/**
 * @brief Sorts an array in ascending order using the bubble sort algorithm.
 *
 * @param arr The array to be sorted.
 * @param size The size of the array.
 *
 * @return void
 */
void bubbleSort(int arr[], int size)
{
  // Perform bubble sort by iterating through the array.
  for (int i = 0; i < size - 1; i++)
  {
    // Loop through the array from the start to size - i - 1.
    for (int j = 0; j < size - i - 1; j++)
    {
      // If the current element is greater than the next, swap them.
      if (arr[j] > arr[j + 1])
      {
        // Swap the elements using a temporary variable.
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
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

  // Sort the array using the bubble sort algorithm.
  bubbleSort(arr, size);

  // Perform a binary search to find the target value in the array.
  int index = binarySearch(arr, 0, size - 1, target);

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