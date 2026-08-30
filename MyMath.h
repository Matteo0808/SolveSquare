/**
 ****************************************
 * @file MyMath.h
 * @brief All mathematic needs in program
 ****************************************
*/

#ifndef MYMATH_H_
#define MYMATH_H_

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "Config.h"
#include "MyAssert.h"

/// @brief Solving of quadratic equation
/// @param coeffs copy of coefficients to solve equation
/// @param roots address of roots to change their values
/// @return No_Roots_In_Real_Numbers - discriminant < 0, start solving in complex numbers\
/// @return Infinite_Number_Of_Roots - a = 0, b = 0, c = 0, infinite number of roots\
/// @return No_Roots - a = 0, b = 0, c != 0, no roots\
/// @return One_Root_Zero_A - a = 0, b != 0, 1 root \
/// @return Two_Roots - 2 real roots\
/// @return One_Root_Zero_D - discrtiminant = 0, 1 root
Case SolveSquare(Coefficients coeffs, Roots* roots);

/// @brief Solving of linear equation
/// @param coeffs copy of coefficients to solve equation
/// @param roots address of roots to change their values
void SolveLinear(Coefficients coeffs, Roots* roots);

/// @brief Solving of one root, when discriminant = 0
/// @param coeffs copy of coefficients to solve equation
/// @param roots address of roots to change their values
void SolveZeroD(Coefficients coeffs, Roots* roots);

/// @brief Solving of quadrtic equation in complex numbers
/// @param coeffs copy of coefficients to solve equation
/// @param roots address of roots to change their values
void SolveComplex(Coefficients coeffs, Roots* roots);

/// @brief Output of the answer
/// @param roots copy of roots to output them
void Answer(Roots roots);

/// @brief Comparison of double numbers with EPS accuracy
/// @param number1 First double number
/// @param number2 Second double number
/// @return 1 - numbers are equal
/// @return 0 - numbers aren't equal
bool IsEqual(const double number1, const double number2);

#endif