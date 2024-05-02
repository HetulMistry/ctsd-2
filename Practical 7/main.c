#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/**
 * @brief Merges two sorted subarrays into one sorted array.
 *
 * @param arr The array containing the subarrays to merge.
 * @param left The starting index of the left subarray.
 * @param mid The ending index of the left subarray and starting index of the right subarray.
 * @param right The ending index of the right subarray.
 *
 * @return void
 */
void merge(int arr[], int left, int mid, int right)
{
  // Calculate the sizes of the left and right subarrays.
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Allocate memory for the left and right subarrays.
  int *leftArr = (int *)malloc(n1 * sizeof(int));
  int *rightArr = (int *)malloc(n2 * sizeof(int));

  // Copy data from the original array to the left and right subarrays.
  for (int i = 0; i < n1; i++)
    leftArr[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    rightArr[j] = arr[mid + 1 + j];

  // Initialize pointers for merging the two subarrays.
  int i = 0;    // Initial index for left subarray.
  int j = 0;    // Initial index for right subarray.
  int k = left; // Initial index for the merged subarray.

  // Merge the left and right subarrays.
  while (i < n1 && j < n2)
  {
    // Compare the elements from leftArr and rightArr.
    if (leftArr[i] <= rightArr[j])
    {
      // Place the smaller element into the merged array.
      arr[k] = leftArr[i];
      i++;
    }
    else
    {
      // Place the smaller element into the merged array.
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  // Copy remaining elements from the left subarray (if any).
  while (i < n1)
  {
    arr[k] = leftArr[i];
    i++;
    k++;
  }

  // Copy remaining elements from the right subarray (if any).
  while (j < n2)
  {
    arr[k] = rightArr[j];
    j++;
    k++;
  }

  // Free the memory allocated for leftArr and rightArr.
  free(leftArr);
  free(rightArr);
}

/**
 * @brief Recursively sorts an array using the merge sort algorithm.
 *
 * @param arr The array to be sorted.
 * @param left The starting index of the array to sort.
 * @param right The ending index of the array to sort.
 *
 * @return void
 */
void mergeSort(int arr[], int left, int right)
{
  // Base condition: if the left index is less than the right index.
  if (left < right)
  {
    // Calculate the middle index.
    int mid = left + (right - left) / 2;

    // Recursively sort the left half of the array.
    mergeSort(arr, left, mid);
    // Recursively sort the right half of the array.
    mergeSort(arr, mid + 1, right);

    // Merge the two sorted halves.
    merge(arr, left, mid, right);
  }
}

/**
 * @brief Prints an array to the console.
 *
 * @param arr The array to be printed.
 * @param size The size of the array.
 *
 * @return void
 */
void printArray(int arr[], int size)
{
  // Iterate through the array and print each element.
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  // Print a newline character at the end of the array.
  printf("\n");
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
  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }

  // Print the original array.
  printf("Original array: ");
  printArray(arr, size);

  // Sort the array using merge sort.
  mergeSort(arr, 0, size - 1);

  // Print the sorted array.
  printf("Sorted array: ");
  printArray(arr, size);

  // Free the dynamically allocated memory.
  free(arr);
  // Wait for a key press before exiting.
  getch();
  // Return 0 to indicate successful execution.
  return 0;
}