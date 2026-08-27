//  Константы

#ifndef CONST_H_   
#define CONST_H_
#include <stdio.h>

#define CONTINUE 2
#define ERRROR 1
#define SUCCESS 0

const unsigned short MAX = 5;

// Погрешность
const double EPS = 1e-6;

//  Случаи при решении квадратных уравнений
enum Case {
    No_Roots_In_Real_Numbers,
    Infinite_Number_Of_Roots,
    No_Roots,
    One_Root_Zero_A,
    Two_Roots,
    One_Root_Zero_D
};

struct Coefficients {
    double a;
    double b;
    double c;
};

// Все составляющие квадратного уравнения
struct Roots {
    Case case_solution;
    double x1;
    double x2;
    double x_for_zero_a;
    double x_for_zero_D;
    double x1_real_part;
    double x1_imagine_part;
};

struct Equation {
    Coefficients coeffs;
    Roots roots;
};

// Цвета
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