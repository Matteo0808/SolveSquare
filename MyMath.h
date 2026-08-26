#ifndef MYMATH_H_
#define MYMATH_H_

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Const.h"
#include "MyAssert.h"

Case SolveSquare(Roots* MainRoots);
void SolveLinear(Roots* MainRoots);
void SolveZeroD(Roots* MainRoots);
void SolveComplex(Roots* MainRoots);
void Answer(Roots* MainRoots);
int IsEqual(const double number1, const double number2);

#endif