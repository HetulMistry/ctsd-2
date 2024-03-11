#include <stdio.h>
#include <conio.h>

/**
 * @brief Function to reverse elements within a given range in a sorted list.
 *
 * @param arr   The array containing the elements.
 * @param start The start index of the range to be reversed.
 * @param end   The end index of the range to be reversed.
 */
void reverseRange(int arr[], int start, int end)
{
  // Check if the start index is greater than the end index or if the range is invalid
  if (start >= end)
  {
    printf("Invalid range!\n"); // Print error message for invalid range
    return;                     // Exit function
  }

  // Reverse the elements within the given range
  while (start < end)
  { // Loop until start index is less than end index
    // Swap the elements at start and end indices
    int temp = arr[start]; // Store the element at start index in temp variable
    arr[start] = arr[end]; // Assign the element at end index to the start index
    arr[end] = temp;       // Assign the temp variable to the end index

    // Move start index towards the end and end index towards the start
    start++; // Increment start index
    end--;   // Decrement end index
  }
}

int main()
{
  int n, i, start, end;

  printf("Enter the number of elements: ");
  scanf("%d", &n); // Read the number of elements from the user

  int arr[n]; // Declare an array of size n

  printf("Enter %d integers:\n", n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]); // Read the elements of the array from the user
  }

  printf("Enter the range (start and end indices): ");
  scanf("%d %d", &start, &end); // Read the start and end indices of the range from the user

  // Check if the range is valid
  if (start < 0 || end >= n || start > end)
  {
    printf("Invalid range!\n"); // Print error message for invalid range
    return 0;                   // Exit program
  }

  // Reverse the elements within the given range
  reverseRange(arr, start, end);

  printf("Array after reversing elements within the range: ");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]); // Print the modified array
  }
  printf("\n");

  // Wait for the user for the keypress
  getch();
  return 0;
}