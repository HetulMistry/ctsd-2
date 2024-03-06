#include "complex.h"

/**
 * @brief The main function of the program.
 *
 * @return Integer value indicating the exit status of the program.
 */
int main(void)
{
  printf("For Num1, ");        // Prompt the user for the first complex number
  complex num1 = getComplex(); // Call the getComplex() function to input the first complex number

  printf("For Num2, ");        // Prompt the user for the second complex number
  complex num2 = getComplex(); // Call the getComplex() function to input the second complex number

  complex addResult = addComplex(num1, num2);           // Calculate the sum of the complex numbers
  complex multiplyResult = multiplyComplex(num1, num2); // Calculate the product of the complex numbers

  printf("Addition of complex number :"); // Print a message indicating addition operation
  displayComplex(addResult);              // Display the sum of the complex numbers

  printf("Multiplication of complex number :"); // Print a message indicating multiplication operation
  displayComplex(multiplyResult);               // Display the product of the complex numbers

  getch();  // Wait for a key press
  return 0; // Return 0 to indicate successful program execution
}