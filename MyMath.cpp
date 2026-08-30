//  Вся математика

#include "MyMath.h"

/// @brief Comparison of double numbers with EPS accuracy
/// @param number1 First double number
/// @param number2 Second double number
/// @return 1 - numbers are equal
/// @return 0 - numbers aren't equal
bool IsEqual(const double number1, const double number2){

    if (fabs(number1 - number2) < EPS){
        return 1;
    }
    else{
        return 0;
    }
}

/// @brief Solving of quadratic equation
/// @param coeffs copy of coefficients to solve equation
/// @param roots address of roots to change their values
/// @return No_Roots_In_Real_Numbers - discriminant < 0, start solving in complex numbers\
/// @return Infinite_Number_Of_Roots - a = 0, b = 0, c = 0, infinite number of roots\
/// @return No_Roots - a = 0, b = 0, c != 0, no roots\
/// @return One_Root_Zero_A - a = 0, b != 0, 1 root \
/// @return Two_Roots - 2 real roots\
/// @return One_Root_Zero_D - discrtiminant = 0, 1 root
Case SolveSquare(Coefficients coeffs, Roots *roots){
    MyAssert(roots);
    // printf("%lg %lg %lg\n", coeff.a, coeffs.b, coeffs.c);

    if (!IsEqual(coeffs.a, 0)){

        double D = 0; ///< discriminant
        D = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;

        if (D > EPS){        //  Погрешность EPS = 1e-6

            double sqrt_D = 0; ///< square root of discriminant
            sqrt_D = sqrt(D);

            roots->x1 = (-coeffs.b + sqrt_D) / (2 * coeffs.a); // больший корень
            roots->x2 = (-coeffs.b - sqrt_D) / (2 * coeffs.a); // меньший корень

            return Two_Roots; // 2 решения
        }
        else if (IsEqual(D, 0)){
            SolveZeroD(coeffs, roots);
            return One_Root_Zero_D; // 1 решение(x1 = x2)
        }
        else{
            SolveComplex(coeffs, roots);
            return No_Roots_In_Real_Numbers; // нет решений(действительных)
        }
    }
    if (!IsEqual(coeffs.b, 0)){
        SolveLinear(coeffs, roots);
        return One_Root_Zero_A; // 1 решение(a = 0)
    }
    if (!IsEqual(coeffs.c, 0)){
        return No_Roots; // нет решений(a = 0, b = 0, c != 0)
    }
    return Infinite_Number_Of_Roots;
}

/// @brief Solving of linear equation
/// @param coeffs copy of coefficients to solve equation
/// @param roots address of roots to change their values
void SolveLinear(Coefficients coeffs, Roots *roots){
    MyAssert(roots);

    roots->x_for_zero_a = -coeffs.c / coeffs.b;
}

/// @brief Solving of one root, when discriminant = 0
/// @param coeffs copy of coefficients to solve equation
/// @param roots address of roots to change their values
void SolveZeroD(Coefficients coeffs, Roots *roots){
    MyAssert(roots);

    roots->x_for_zero_D = -coeffs.b / (2 * coeffs.a);
}

/// @brief Solving of quadrtic equation in complex numbers
/// @param coeffs copy of coefficients to solve equation
/// @param roots address of roots to change their values
void SolveComplex(Coefficients coeffs, Roots *roots){
    MyAssert(roots);

    double D_complex = 0; ///< disriminant for eqaution with complex roots multiplied by -1
    D_complex = -1 * (coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c);

    double sqrt_D_complex = 0; ///< sqaure_root of complex discriminant
    sqrt_D_complex = sqrt(D_complex);

    roots->x1_real_part = (-coeffs.b) / (2 * coeffs.a);
    roots->x1_imagine_part = sqrt_D_complex / (2 * coeffs.a);
}
/// @brief Output of the answer
/// @param roots copy of roots to output them
void Answer(Roots roots){
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

        case No_Roots_In_Real_Numbers:
            printf(PURPLE_TEXT ORANGE_BG "No roots in real numbers\n" CLEAR);
            printf(PURPLE_TEXT ORANGE_BG "The equation has 2 complex roots:\nx1 = %lg + %lgi\tx2 = %lg - %lgi\n" CLEAR,
                roots.x1_real_part, roots.x1_imagine_part, roots.x1_real_part, roots.x1_imagine_part);
            break;

        default:
            MyAssert(1);
    }
}