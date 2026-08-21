#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "MyMath.h"
#include "MyAssert.h"
#include "Input.h"
#include "CheckingNearZero.h"

//#define NDEBUG

void CaseSolution(int case_solution, double a, double b, double c, double* x1, double* x2);

int main(){
    printf("# Solving square equations: ax^2 + bx + c = 0\n");
    printf("# (c) MIM \n");
    printf("# Enter a, b, c:\n");
    
    double a = 0, b = 0, c = 0;

    Input(&a, 'a');
    Input(&b, 'b');
    Input(&c, 'c');

    double x1 = 0, x2 = 0;

    CaseSolution((SolveSquare(a, b, c, &x1, &x2)), a, b, c, &x1, &x2);
    
    return 0;
}

//  Вывод ответа в зависимости от его разновидности
void CaseSolution(int case_solution, double a, double b, double c, double* x1, double* x2){
    assert(x1);
    assert(x2);

    switch (case_solution){
        case One_Root_Zero_D:
            double x_for_zero_D = 0;
            x_for_zero_D = SolveZeroD(a, b, x_for_zero_D);
            printf("The equation has 2 roots, but they are same: x = %lg\n", x_for_zero_D);
            break;
        case Two_Roots:
            printf("The equation has 2 roots:\nx1 = %lg\tx2 = %lg\n", *x1, *x2);
            break;
        case One_Root_Zero_A:
            double x_for_1_root = 0;
            x_for_1_root = SolveLinear(b, c, x_for_1_root);
            printf("The equation has 1 root:\nx = %lg\n", x_for_1_root);
            break;
        case No_Roots:
            printf("No roots\n");
            break;
        case Infinite_Number_Of_Roots:
            printf("Infinite number of roots\n");
            break;
        case No_Root_In_Real_Numbers:
            printf("No roots in real numbers\n");
            SolveComplex(a, b, c, x1, x2);
            printf("The equation has 2 complex roots:\nx1 = %lgi\tx2 = %lgi\n", *x1, *x2);
            break;
    }
}