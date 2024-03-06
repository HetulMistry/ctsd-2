#include <stdio.h>
#include <conio.h>
#include <time.h>

/**
 * @brief Main function to display the current time.
 *
 * @return Integer value indicating the exit status of the program.
 */
int main(void)
{
  time_t t; // Variable to store current time
  time(&t); // Get current time

  printf("\nCurrent Time : %s", ctime(&t)); // Print current time

  getch();  // Wait for a key press
  return 0; // Return 0 to indicate successful program execution
}