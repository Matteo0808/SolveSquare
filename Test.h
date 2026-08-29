/**
 * @file Test.h
 * @brief Testing the program befor start
 */


#ifndef TEST_H_
#define TEST_H_
#include <stdio.h>
#include <string.h>
#include "Const.h"
#include "MyMath.h"
#include "MyAssert.h"

/// @brief Start of testing
/// @return ERRROR - Error in testing\
/// @return SUCCESS - Testing done successfully
Error_or_Success RunMainTest();

/// @brief Start of each test
/// @param ExpectedEquation Struct with reference values to compare gotten roots
/// @param TestEquation Struct to keep values gotten in test
/// @return ERRROR - Error in testing\
/// @return SUCCESS - Testing done successfully
Error_or_Success RunTest(Equation ExpectedEquation, Equation TestEquation);

/// @brief Print of struct, need for debug
/// @param Equ struct to print
/// @param str name of struct
void printEqu(Equation Equ, char str[]);

/// @brief Skanning reference values from file
/// @param TestEquation Pointer to pointer to struct to reallocate the memory
/// @param ExpectedEquation pointer to pointer to struct to reallocate the memory
/// @param init_size Size of array
/// @return ERRROR - Error in scanning from file\
/// @return GoshaKazunin - Size of array
int OpenTestFile(Equation** TestEquation, Equation** ExpectedEquation, int size);

/// @brief Realloc wrapper, replaces garbage values to zero
/// @param Equ Array of structs, that need to clean
/// @param size NewSize - OldSize(by realloc) = OldSize, becouse NewSize = 2*OldSize 
void ReallocNull(Equation* Equ, int size);
#endif