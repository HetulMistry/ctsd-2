#include <stdio.h>
#include <conio.h>

/**
 * @brief Function to perform selection sort on an array of integers.
 *
 * @param arr The array to be sorted.
 * @param n   The number of elements in the array.
 */
void selectionSort(int arr[], int n)
{
  int i, j, minIndex, temp;
  for (i = 0; i < n - 1; i++) // Loop through the array from the first element to the second-to-last element
  {
    minIndex = i; // Assume the current index is the index of the minimum element
    for (j = i + 1; j < n; j++)
    {                             // Loop through the remaining unsorted elements to find the minimum
      if (arr[j] < arr[minIndex]) // If a smaller element is found, update the index of the minimum
      {
        minIndex = j;
      }
    }
    // Swap the minimum element with the current element
    temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}

/**
 * @brief Function to perform bubble sort on an array of integers.
 *
 * @param arr The array to be sorted.
 * @param n   The number of elements in the array.
 */
void bubbleSort(int arr[], int n)
{
  int i, j, temp;
  for (i = 0; i < n - 1; i++) // Loop through the array from the first element to the second-to-last element
  {
    for (j = 0; j < n - i - 1; j++) // Iterate over the unsorted part of the array
    {
      if (arr[j] > arr[j + 1]) // If adjacent elements are out of order, swap them
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main(void)
{
  int n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n); // Read the number of elements from the user

  int arr[n];
  printf("Enter %d integers:\n", n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]); // Read the elements of the array from the user
  }

  printf("Array before selection sort: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]); // Print the array before selection sort
  }
  printf("\n");

  selectionSort(arr, n); // Call the selection sort function

  printf("Array after selection sort: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]); // Print the array after selection sort
  }
  printf("\n");

  printf("Array before bubble sort: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]); // Print the array before bubble sort
  }
  printf("\n");

  bubbleSort(arr, n); // Call the bubble sort function

  printf("Array after bubble sort: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]); // Print the array after bubble sort
  }
  printf("\n");

  // Wait for the user for the keypress
  getch();
  return 0;
}