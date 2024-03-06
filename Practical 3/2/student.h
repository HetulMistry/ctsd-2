#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Structure to represent a student.
 */
typedef struct student
{
  int roll_no;      /**< Roll number of the student. */
  char name[50];    /**< Name of the student. */
  char gender;      /**< Gender of the student (M/F). */
  float marks[5];   /**< Marks obtained by the student in 5 subjects. */
  float percentage; /**< Percentage calculated based on the marks obtained. */
} Student;

/**
 * @brief Calculates the percentage for each student.
 *
 * @param student Array of Student objects.
 * @param n Number of students.
 */
void calculatePercentage(Student *student, int n)
{
  // Loop through each student
  for (int i = 0; i < n; i++)
  {
    float total = 0;
    // Calculate the total marks obtained by the student
    for (int j = 0; j < 5; j++)
    {
      total += student[i].marks[j];
    }
    // Calculate the percentage and assign it to the student's percentage field
    student[i].percentage = (total / 5.0);
  }
}

/**
 * @brief Sorts the students array based on percentage in descending order.
 *
 * @param student Array of Student objects.
 * @param n Number of students.
 */
void sortByPercentage(Student *student, int n)
{
  // Bubble sort algorithm
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      // Compare percentages and swap if necessary to sort in descending order
      if (student[j].percentage < student[j + 1].percentage)
      {
        // Swap the students array
        Student temp = student[j];
        student[j] = student[j + 1];
        student[j + 1] = temp;
      }
    }
  }
}

/**
 * @brief Displays the student list sorted by percentage.
 *
 * @param student Array of Student objects.
 * @param n Number of students.
 */
void displayStudents(Student *student, int n)
{
  // Display the header for the student list
  printf("\nStudent List Sorted by Percentage:\n");
  printf("---------------------------------\n");
  printf("Roll No\tName\tGender\tPercentage\n");
  printf("---------------------------------\n");
  // Display details of each student in the sorted order
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%s\t%c\t%.2f%%\n", student[i].roll_no, student[i].name, student[i].gender, student[i].percentage);
  }
}