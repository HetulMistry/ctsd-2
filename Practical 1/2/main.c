#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/**
 * @brief Increase the number of subarrays in a 2D array.
 *
 * @param arr The 2D array to modify.
 * @param rows Pointer to the number of rows in the array.
 * @param cols Pointer to the number of columns in the array.
 */
void increaseSubarrays(int arr[][100], int *rows, int *cols)
{
  (*rows)++; // Increment the number of rows.
}

/**
 * @brief Decrease the number of subarrays in a 2D array if possible.
 *
 * @param arr The 2D array to modify.
 * @param rows Pointer to the number of rows in the array.
 * @param cols Pointer to the number of columns in the array.
 */
void decreaseSubarrays(int arr[][100], int *rows, int *cols)
{
  if (*rows > 0) // If there are rows present.
  {
    (*rows)--; // Decrement the number of rows.
  }
}

/**
 * @brief Increase the number of elements in each subarray of a 2D array.
 *
 * @param arr The 2D array to modify.
 * @param rows Pointer to the number of rows in the array.
 * @param cols Pointer to the number of columns in the array.
 */
void increaseElements(int arr[][100], int *rows, int *cols)
{
  (*cols)++; // Increment the number of columns.
}

/**
 * @brief Decrease the number of elements in each subarray of a 2D array if possible.
 *
 * @param arr The 2D array to modify.
 * @param rows Pointer to the number of rows in the array.
 * @param cols Pointer to the number of columns in the array.
 */
void decreaseElements(int arr[][100], int *rows, int *cols)
{
  if (*cols > 0) // If there are columns present.
  {
    (*cols)--; // Decrement the number of columns.
  }
}

/**
 * @brief Display the elements of a 2D array.
 *
 * @param arr The 2D array to display.
 * @param rows The number of rows in the array.
 * @param cols The number of columns in the array.
 */
void displayArray(int arr[][100], int rows, int cols)
{
  for (int i = 0; i < rows; i++) // Loop through each row.
  {
    for (int j = 0; j < cols; j++) // Loop through each column.
    {
      printf("%d ", arr[i][j]); // Print the element at position (i, j).
    }
    printf("\n"); // Move to the next line after printing all elements of a row.
  }
}

/**
 * @brief Main function to demonstrate the functionality of the program.
 *
 * @return Returns 0 upon successful execution.
 */
int main(void)
{
  int rows, cols;

  printf("Enter the number of rows and columns: "); // Prompt the user to enter the dimensions of the array.
  scanf("%d %d", &rows, &cols);                     // Read the dimensions of the array.

  int arr[100][100]; // Declare a 2D array with maximum size 100x100.

  printf("Enter the elements of the array:\n"); // Prompt the user to enter the elements of the array.
  for (int i = 0; i < rows; i++)                // Loop through each row.
  {
    for (int j = 0; j < cols; j++) // Loop through each column.
    {
      scanf("%d", &arr[i][j]); // Read the element at position (i, j).
    }
  }

  int choice; // Variable to store user's choice.

  do
  {
    printf("\n1. Increase number of subarrays\n"); // Display menu options.
    printf("2. Decrease number of subarrays\n");
    printf("3. Increase number of elements in subarrays\n");
    printf("4. Decrease number of elements in subarrays\n");
    printf("5. Display array\n");
    printf("6. Exit\n");
    printf("Enter your choice: "); // Prompt the user to enter their choice.
    scanf("%d", &choice);          // Read user's choice.

    switch (choice) // Perform actions based on user's choice.
    {
    case 1:
      increaseSubarrays(arr, &rows, &cols); // Increase the number of subarrays.
      break;
    case 2:
      decreaseSubarrays(arr, &rows, &cols); // Decrease the number of subarrays.
      break;
    case 3:
      increaseElements(arr, &rows, &cols); // Increase the number of elements in subarrays.
      break;
    case 4:
      decreaseElements(arr, &rows, &cols); // Decrease the number of elements in subarrays.
      break;
    case 5:
      displayArray(arr, rows, cols); // Display the array.
      break;
    case 6:
      printf("Exiting...\n"); // Exit the program.
      break;
    default:
      printf("Invalid choice\n"); // Display error message for invalid choices.
    }
  } while (choice != 6); // Continue the loop until user chooses to exit.

  getch();  // Wait for a key press before exiting.
  return 0; // Return 0 to indicate successful execution.
}