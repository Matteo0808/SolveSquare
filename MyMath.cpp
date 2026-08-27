//  Вся математика
#include "MyMath.h"


//  Решение квадратного уравнения

int IsEqual(const double number1, const double number2){
    if(fabs(number1 - number2) < EPS){
        return 1;
    }
    else{
        return 0;
    }
}

Case SolveSquare(Coefficients coeffs, Roots* roots){
    MyAssert(roots);
    //printf("%lg %lg %lg\n", coeff.a, coeffs.b, coeffs.c);

    if(IsEqual(coeffs.a, 0)){

        if(IsEqual(coeffs.b, 0)){

            if(IsEqual(coeffs.c, 0)){
                return Infinite_Number_Of_Roots; // бесконечное количество решений
            }

            else{ // c != 0
                return No_Roots; // нет решений(a = 0, b = 0, c != 0)
            }

        }

        else{ // b != 0
            SolveLinear(coeffs, roots);
            return One_Root_Zero_A; // 1 решение(a = 0)
        }

    }

    else{
        double D = 0;
        D = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;

        if(D > 0){
            
            double sqrt_D = 0;
            sqrt_D = sqrt(D);

            roots->x1 = (-coeffs.b + sqrt_D)/(2 * coeffs.a); // большее
            roots->x2 = (-coeffs.b - sqrt_D)/(2 * coeffs.a); // меньшее

            return Two_Roots; // 2 решения
        }
        
        else if(IsEqual(D, 0)){
            SolveZeroD(coeffs, roots);
            return One_Root_Zero_D; // 1 решение(x1 = x2)
        }
        
        else if(D < 0){
            SolveComplex(coeffs, roots);
            //printf("%lg\n", D);
            return No_Root_In_Real_Numbers; // нет решений(действительных)
        }

    }

    return 0;
}

//  Решение линейного уравнения при a = 0
void SolveLinear(Coefficients coeffs, Roots* roots){
    MyAssert(roots);
    
    roots->x_for_zero_a = -coeffs.c / coeffs.b;
}

// Нахождение единственного корня при D = 0
void SolveZeroD(Coefficients coeffs, Roots* roots){
    MyAssert(roots);
    
    roots->x_for_zero_D = -coeffs.b / (2 * coeffs.a);
}

//  Нахождение мнимых корней
void SolveComplex(Coefficients coeffs, Roots* roots){
    MyAssert(roots);    

    double D_complex = 0;
    D_complex = -1 * (coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c);

    double sqrt_D_complex = 0;
    sqrt_D_complex = sqrt(D_complex);

    roots->x1_real_part = (-coeffs.b) / (2 * coeffs.a);
    roots->x1_imagine_part = sqrt_D_complex / (2 * coeffs.a);

}
//  Вывод ответа
void Answer(Roots roots){
    //MyAssert(MainRoots);
    
    switch (roots.case_solution){
        
        case One_Root_Zero_D:
            printf(PURPLE_TEXT ORANGE_BG "The equation has 2 roots, but they are same: x = %lg\n" CLEAR, roots.x_for_zero_D);
            break;

        case Two_Roots:
            printf(PURPLE_TEXT ORANGE_BG "The equation has 2 roots:\nx1 = %lg\tx2 = %lg\n" CLEAR, roots.x1, roots.x2);
            break;

        case One_Root_Zero_A:
            printf(PURPLE_TEXT ORANGE_BG "The equation has 1 root:\nx = %lg\n" CLEAR, roots.x_for_zero_a);
            break;

        case No_Roots:
            printf(PURPLE_TEXT ORANGE_BG "No roots\n" CLEAR);
            break;

        case Infinite_Number_Of_Roots:
            printf(PURPLE_TEXT ORANGE_BG "Infinite number of roots\n" CLEAR);
            break;

        case No_Root_In_Real_Numbers:
            printf(PURPLE_TEXT ORANGE_BG "No roots in real numbers\n" CLEAR);
            printf(PURPLE_TEXT ORANGE_BG "The equation has 2 complex roots:\nx1 = %lg + %lgi\tx2 = %lg - %lgi\n" CLEAR, \
                roots.x1_real_part, roots.x1_imagine_part, roots.x1_real_part, roots.x1_imagine_part);
            break;

    }
}



// __VA_ARGS__ 