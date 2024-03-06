#include <stdio.h>
#include <conio.h>

// Macro definition
#define SQUARE(x) ((x) * (x))

// Conditional compilation
#define DEBUG 1

/**
 * @brief Main function of the program.
 *
 * @return Integer value indicating the exit status of the program.
 */
int main(void)
{
  // Macros
  int num = 5;
  printf("Square of %d is %d\n", num, SQUARE(num));

  // Conditional compilation
#if DEBUG
  printf("Debug mode is enabled.\n");
#else
  printf("Debug mode is disabled.\n");
#endif

  getch();  // Wait for a key press
  return 0; // Return 0 to indicate successful program execution
}
