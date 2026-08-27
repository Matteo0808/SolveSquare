#ifndef TEST_H_
#define TEST_H_
#include <stdio.h>
#include "Const.h"
#include "MyMath.h"
#include "MyAssert.h"

int RunMainTest();
int RunTest(Equation ExpectedEquation, Equation TestEquation);
int OpenTestFile(Equation TestEquation[], Equation ExpectedEquation[], int size);

#endif