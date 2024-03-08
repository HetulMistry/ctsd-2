#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

/**
 * @brief Structure to represent an employee.
 */
typedef struct employee
{
  int EMP_ID;        /**< Employee ID. */
  char EMP_NAME[50]; /**< Employee name. */
  int EMP_DEPTID;    /**< Department ID of the employee. */
  long EMP_PHNO;     /**< Phone number of the employee. */
  float EMP_SALARY;  /**< Salary of the employee. */
} Employee;

/**
 * @brief Swaps two Employee objects.
 *
 * @param a Pointer to the first Employee object.
 * @param b Pointer to the second Employee object.
 */
void swap(Employee *a, Employee *b)
{
  // Simple swapping
  Employee temp = *a;
  *a = *b;
  *b = temp;
}

/**
 * @brief Sorts an array of Employee objects based on employee names in ascending order using bubble sort.
 *
 * @param arr Array of Employee objects.
 * @param n Number of employees.
 */
void bubbleSort(Employee arr[], int n)
{
  int i, j;
  // Iterate through the array
  for (i = 0; i < n - 1; i++)
  {
    // Compare adjacent elements and swap if necessary
    for (j = 0; j < n - i - 1; j++)
    {
      if (strcmp(arr[j].EMP_NAME, arr[j + 1].EMP_NAME) > 0)
      {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

/**
 * @brief Displays the details of employees.
 *
 * @param arr Array of Employee objects.
 * @param n Number of employees.
 */
void displayEmployees(Employee arr[], int n)
{
  // Print the header for the employee details
  printf("EMP_ID\tEMP_NAME\tEMP_DEPTID\tEMP_PHNO\tEMP_SALARY\n");
  // Loop through each employee and print their details
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%s\t\t%d\t\t%ld\t%.2f\n", arr[i].EMP_ID, arr[i].EMP_NAME, arr[i].EMP_DEPTID, arr[i].EMP_PHNO, arr[i].EMP_SALARY);
  }
}
