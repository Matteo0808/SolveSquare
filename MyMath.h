#ifndef MYMATH_H_
#define MYMATH_H_

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Const.h"
#include "MyAssert.h"

Case SolveSquare(Coefficients coeffs, Roots* roots);
void SolveLinear(Coefficients coeffs, Roots* roots);
void SolveZeroD(Coefficients coeffs, Roots* roots);
void SolveComplex(Coefficients coeffs, Roots* roots);
void Answer(Roots roots);
int IsEqual(const double number1, const double number2);

#endif