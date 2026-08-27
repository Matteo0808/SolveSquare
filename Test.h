#ifndef TEST_H_
#define TEST_H_
#include <stdio.h>
#include "Const.h"
#include "MyMath.h"
#include "MyAssert.h"

Error_or_Success RunMainTest();
Error_or_Success RunTest(Equation ExpectedEquation, Equation TestEquation);
Error_or_Success OpenTestFile(Equation TestEquation[], Equation ExpectedEquation[], int size);

#endif