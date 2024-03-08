#include "employee.h"

/**
 * @brief Main function of the program.
 *
 * @return Integer value indicating the exit status of the program.
 */
int main(void)
{
  Employee employees[MAX_EMPLOYEES];
  int n, i;

  // Prompt user to input the number of employees
  printf("Enter the number of employees: ");
  scanf("%d", &n);

  // Validate input number of employees
  if (n <= 0 || n > MAX_EMPLOYEES)
  {
    printf("Invalid number of employees.");
    return 1;
  }

  // Input employee details
  printf("Enter employee details:\n");
  for (i = 0; i < n; i++)
  {
    // Input employee ID
    printf("EMP_ID: ");
    scanf("%d", &employees[i].EMP_ID);

    // Input employee name
    printf("EMP_NAME: ");
    scanf("%s", employees[i].EMP_NAME);

    // Input department ID
    printf("EMP_DEPTID: ");
    scanf("%d", &employees[i].EMP_DEPTID);

    // Input phone number
    printf("EMP_PHNO: ");
    scanf("%ld", &employees[i].EMP_PHNO);

    // Input salary
    printf("EMP_SALARY: ");
    scanf("%f", &employees[i].EMP_SALARY);
  }

  // Sort employees based on name
  bubbleSort(employees, n);

  // Display sorted employee records
  printf("\nSorted Employee Records:\n");
  displayEmployees(employees, n);

  // Wait for a key press before exiting
  getch();
  return 0;
}