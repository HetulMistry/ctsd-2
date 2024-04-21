#include <stdio.h>
#include <conio.h>

/**
 * @brief Sorts an array using the Insertion Sort algorithm.
 *
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void insertionSort(int arr[], int n);

/**
 * @brief Sorts a partition of an array using the Quick Sort algorithm.
 *
 * @param arr The array to be sorted.
 * @param low The starting index of the partition to be sorted.
 * @param high The ending index of the partition to be sorted.
 */
void quickSort(int arr[], int low, int high);

/**
 * @brief Partitions an array for the Quick Sort algorithm.
 *
 * @param arr The array to be partitioned.
 * @param low The starting index of the partition.
 * @param high The ending index of the partition.
 *
 * @return int The index of the pivot element after partitioning.
 */
int partition(int arr[], int low, int high);

/**
 * @brief Swaps the values of two integers.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    /* Move elements of arr[0..i-1], that are greater than key,
    to one position ahead of their current position */
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// Function to partition the array using Quick Sort
int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1); // Index of smaller element

  for (int j = low; j <= high - 1; j++)
  {
    // If current element is smaller than or equal to pivot
    if (arr[j] <= pivot)
    {
      i++; // Increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    /* pi is partitioning index, arr[pi] is now at right place */
    int pi = partition(arr, low, high);

    // Separately sort elements before partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

/**
 * @brief Prints the elements of an array.
 *
 * @param arr The array to be printed.
 * @param size The number of elements in the array.
 */
void printArray(int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

/**
 * @brief Main function to test the sorting algorithms.
 *
 * @return int Return 0 on successful execution.
 */
int main(void)
{
  int n;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int arr[n], arr2[n];

  printf("Enter %d elements:\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
    arr2[i] = arr[i]; // Copying elements for Quick Sort
  }

  printf("\nArray before sorting: \n");
  printArray(arr, n);

  // Perform Insertion Sort
  insertionSort(arr, n);
  printf("\nArray after Insertion Sort: \n");
  printArray(arr, n);

  printf("\nArray before sorting: \n");
  printArray(arr2, n);

  // Perform Quick Sort
  quickSort(arr2, 0, n - 1);
  printf("\nArray after Quick Sort: \n");
  printArray(arr2, n);

  // Wait for key press before exiting the program
  getch();
  return 0;
}