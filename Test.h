#ifndef TEST_H_
#define TEST_H_
#include <stdio.h>
#include <string.h>
#include "Const.h"
#include "MyMath.h"
#include "MyAssert.h"

Error_or_Success RunMainTest();
Error_or_Success RunTest(Equation ExpectedEquation, Equation TestEquation);
void printEqu(Equation Equ, char str[]);
int OpenTestFile(Equation** TestEquation, Equation** ExpectedEquation, int size);
void ReallocNull(Equation* Equ, int size);
#endif