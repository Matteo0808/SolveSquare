/**
 ******************************
 * @file Input.h
 * @brief Input of coefficients
 ******************************
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include "Config.h"

/// @brief define to make char from letter
#define MAKECHAR(sym) #sym[0]

/// @brief define of general input
#define SAFEINPUT(coefficient) Input(&(coeffs->coefficient), MAKECHAR(coefficient))

/// @brief Entering coefficient with checking for erroneous input
/// @param coeff Each coefficient
/// @return ERRROR - program exits with an error\
/// @return SUCCESS - program completed successfully
Error_or_Success FuncScanf(double* coeff);

/// @brief This function is called in main to start input
/// @param coeffs Pointer to the coefficients that will be changed
void MainInput(Coefficients* coeff);

/// @brief Intro text printing
void PrintInput();

/// @brief Input of each coefficient
/// @param coeff Pointer to each coefficient
/// @param sym char symbol of coefficient
void Input(double* coeff, char sym);

/// @brief Cleaning the buffer
void BufferClean();

#endif