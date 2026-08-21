#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "CheckingNearZero.h"

#ifndef MYMATH_H_
    #define MEMATH_H_
    int SolveSquare(double a, double b, double c, double* x1, double* x2);
    int SolveLinear(double b, double c, double x);
    int SolveZeroD(double a, double b, double x);
    void SolveComplex(double a, double b, double c, double* x1, double* x2);

    //  Решение квадратного уравнения
    int SolveSquare(double a, double b, double c, double* x1, double* x2){
        // assert(x1);
        // assert(x2);

        if(CheckingNearZero(a)){
            if(CheckingNearZero(b)){
                if(CheckingNearZero(c)){
                    return Infinite_Number_Of_Roots; // бесконечное количество решений
                }
                else{ // c != 0 
                    return No_Roots; // нет решений(a = 0, b = 0, c != 0)
                }
            }
            else{ // b != 0
                return One_Root_Zero_A; // 1 решение(a = 0)
            }
        }
        else{
            double D = 0;
            D = b*b - 4*a*c;
            if(D > 0){
                double sqrt_D = 0;
                sqrt_D = sqrt(D);
            
                *x1 = (-b + sqrt_D)/(2*a);
                *x2 = (-b - sqrt_D)/(2*a);
            
            return Two_Roots; // 2 решения
            }
            else if(CheckingNearZero(D)){
                return One_Root_Zero_D; // 1 решение(x1 = x2)
            }
            else if(D < 0){
                return No_Root_In_Real_Numbers; // нет решений(действительных)
            }
            
        }
    }

    //  Решение линейного уравнения при a = 0
    int SolveLinear(double b, double c, double x){
        x = -c/b;
        return x;
    }

    // Нахождение единственного корня при D = 0 
    int SolveZeroD(double a, double b, double x){
        x = -b/(2*a);
        return x;
    }

    //  Нахождение мнимых корней
    void SolveComplex(double a, double b, double c, double* x1, double* x2){
        assert(x1);
        assert(x2);

        double D_complex = 0;
        D_complex = -1*(b*b - 4*a*c);

        double sqrt_D_complex = 0;
        sqrt_D_complex = sqrt(D_complex);
            
        *x1 = (-b + sqrt_D_complex)/(2*a);
        *x2 = (-b - sqrt_D_complex)/(2*a);
    }
#endif