//  Константы

#ifndef CONST_H_   
#define CONST_H_
#include <stdio.h>

//#define CONTINUE 2
// #define ERRROR 1
// #define SUCCESS 0

/// @brief Accuracy in double numbers comparison
const double EPS = 1e-6;

/// @brief Returns of error and success
enum Error_or_Success {
    ERRROR = -1,
    SUCCESS = 0
};

/// @brief Cases in solving quadratic equation
enum Case {
    No_Roots_In_Real_Numbers = 0,
    Infinite_Number_Of_Roots = 1,
    No_Roots = 2,
    One_Root_Zero_A = 3,
    Two_Roots = 4,
    One_Root_Zero_D = 5
};

/// @brief Struct of coefficients
struct Coefficients {
    double a;
    double b;
    double c;
};

/// @brief Struct of roots
struct Roots {
    Case case_solution;
    double x1;
    double x2;
    double x_for_zero_a;
    double x_for_zero_D;
    double x1_real_part;
    double x1_imagine_part;
};

/// @brief General struct of full equation
struct Equation {
    Coefficients coeffs;
    Roots roots;
};

/// @brief Colors' cods
    #define RED_TEXT "\033[91m"
    #define RED_BG "\033[101m"
    #define PURPLE_TEXT "\033[95m"
    #define PURPLE_BG "\033[105m"
    #define ORANGE_TEXT "\033[93m"
    #define ORANGE_BG "\033[103m"
    #define GREEN_BG "\e[42m"
    #define WHITE_TEXT "\e[0;37m"
    #define CLEAR  "\033[0m"
    
#endif