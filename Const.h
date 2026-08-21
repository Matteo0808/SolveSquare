#include <stdio.h>
#ifndef CONST_H_   
    #define CONST_H_
    const double EPS = 1e-9;

    //  Случаи при решении квадратных уравнений
    enum Case{
        No_Root_In_Real_Numbers,
        Infinite_Number_Of_Roots,
        No_Roots,
        One_Root_Zero_A,
        Two_Roots,
        One_Root_Zero_D
    };
#endif