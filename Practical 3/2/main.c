#include "student.h"

/**
 * @brief Main function of the program.
 *
 * @return Integer value indicating the exit status of the program.
 */
int main(void)
{
  int n;

  // Prompt user to input the number of students
  printf("Enter the number of students: ");
  scanf("%d", &n);

  // Dynamically allocate memory for an array of students
  Student *students = (Student *)malloc(n * sizeof(Student));

  // Input details for each student
  for (int i = 0; i < n; i++)
  {
    printf("Enter details for student %d:\n", i + 1);

    // Input roll number
    printf("Roll No: ");
    scanf("%d", &students[i].roll_no);

    // Input name
    printf("Name: ");
    scanf(" %[^\n]", students[i].name);

    // Input gender
    printf("Gender (M/F): ");
    scanf(" %c", &students[i].gender);

    // Input marks in 5 subjects
    printf("Marks in 5 subjects: ");
    for (int j = 0; j < 5; j++)
    {
      scanf("%f", &students[i].marks[j]);
    }
  }

  // Calculate percentage for each student
  calculatePercentage(students, n);
  // Sort students based on percentage in descending order
  sortByPercentage(students, n);
  // Display the sorted list of students
  displayStudents(students, n);

  // Free dynamically allocated memory
  free(students);

  // Wait for a key press before exiting
  getch();
  return 0;
}