# SQUARE EQUATIONS SOLVER

Hello, GitHub! Here is my Quadratic Equations Solver!

This repository contains the code for a program that solves quadratic equations and a file with reference values for testing.

## How it works?

1. The program tests itself. It takes reference values from *Reference.txt* and than compares them to result of the program's work.
2. After test the program offers the user to input coefficients of quadratic equation
3. Than follows the math part: program calculates the roots
4. Than the program print the answer

There is nothing to care, i provide for incorrect input from the user. The input repeats, until the input won't be correct.

The program works with real numbers, but **Solver** provides for the case of negative discriminant, and is able to calculate complex roots.

Comparison of double numbers is performed with accuracy **EPS = 1 * 10^-6**.


<details>


<summary>Includes:</summary>

<stdio.h>
<stdlib.h>
<math.h>

</details>

