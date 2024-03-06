#include <stdio.h>
#include <conio.h>

/**
 * @brief Structure to represent a complex number.
 */
typedef struct complex
{
  float real; /**< Real part of the complex number. */
  float imag; /**< Imaginary part of the complex number. */
} complex;

/**
 * @brief Function to input a complex number from the user.
 *
 * @return The complex number input by the user.
 */
complex getComplex(void)
{
  complex num; // Declare a variable of type complex to store the input number

  printf("Enter the real and imaginary part: "); // Prompt the user to enter real and imaginary parts
  scanf("%f %f", &num.real, &num.imag);          // Read real and imaginary parts from the user

  return num; // Return the input complex number
}

/**
 * @brief Function to display a complex number.
 *
 * @param num The complex number to be displayed.
 */
void displayComplex(complex num)
{
  printf("%.2f + %.2fi\n", num.real, num.imag); // Print the real and imaginary parts of the complex number
}

/**
 * @brief Function to add two complex numbers.
 *
 * @param num1 The first complex number.
 * @param num2 The second complex number.
 * @return The sum of the two complex numbers.
 */
complex addComplex(complex num1, complex num2)
{
  complex result; // Declare a variable of type complex to store the result

  result.real = num1.real + num2.real; // Add the real parts of the two complex numbers
  result.imag = num1.imag + num2.imag; // Add the imaginary parts of the two complex numbers

  return result; // Return the sum of the complex numbers
}

/**
 * @brief Function to multiply two complex numbers.
 *
 * @param num1 The first complex number.
 * @param num2 The second complex number.
 * @return The product of the two complex numbers.
 */
complex multiplyComplex(complex num1, complex num2)
{
  complex result; // Declare a variable of type complex to store the result

  result.real = num1.real * num2.real - num1.imag * num2.imag; // Calculate the real part of the product
  result.imag = num1.real * num2.imag + num2.real * num1.imag; // Calculate the imaginary part of the product

  return result; // Return the product of the complex numbers
}