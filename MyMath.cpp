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

Case SolveSquare(Roots* MainRoots){
    MyAssert(MainRoots);
    //printf("%lg %lg %lg\n", MainRoots->a, MainRoots->b, MainRoots->c);

    if(IsEqual(MainRoots->a, 0)){

        if(IsEqual(MainRoots->b, 0)){

            if(IsEqual(MainRoots->c, 0)){
                return Infinite_Number_Of_Roots; // бесконечное количество решений
            }

            else{ // c != 0
                return No_Roots; // нет решений(a = 0, b = 0, c != 0)
            }

        }

        else{ // b != 0
            SolveLinear(MainRoots);
            return One_Root_Zero_A; // 1 решение(a = 0)
        }

    }

    else{
        double D = 0;
        D = MainRoots->b * MainRoots->b - 4 * MainRoots->a * MainRoots->c;

        if(D > 0){
            
            double sqrt_D = 0;
            sqrt_D = sqrt(D);

            MainRoots->x1 = (-MainRoots->b + sqrt_D)/(2 * MainRoots->a); // большее
            MainRoots->x2 = (-MainRoots->b - sqrt_D)/(2 * MainRoots->a); // меньшее

            return Two_Roots; // 2 решения
        }
        
        else if(IsEqual(D, 0)){
            SolveZeroD(MainRoots);
            return One_Root_Zero_D; // 1 решение(x1 = x2)
        }
        
        else if(D < 0){
            SolveComplex(MainRoots);
            //printf("%lg\n", D);
            return No_Root_In_Real_Numbers; // нет решений(действительных)
        }

    }

    return 0;
}

//  Решение линейного уравнения при a = 0
void SolveLinear(Roots* MainRoots){
    MyAssert(MainRoots);
    
    MainRoots->x_for_zero_a = -MainRoots->c / MainRoots->b;
}

// Нахождение единственного корня при D = 0
void SolveZeroD(Roots* MainRoots){
    MyAssert(MainRoots);
    
    MainRoots->x_for_zero_D = -MainRoots->b / (2 * MainRoots->a);
}

//  Нахождение мнимых корней
void SolveComplex(Roots* MainRoots){
    MyAssert(MainRoots);    

    double D_complex = 0;
    D_complex = -1 * (MainRoots->b * MainRoots->b - 4 * MainRoots->a * MainRoots->c);

    double sqrt_D_complex = 0;
    sqrt_D_complex = sqrt(D_complex);

    MainRoots->x1_real_part = (-MainRoots->b) / (2 * MainRoots->a);
    MainRoots->x1_imagine_part = sqrt_D_complex / (2 * MainRoots->a);

}
//  Вывод ответа
void Answer(Roots* MainRoots){
    MyAssert(MainRoots);
    
    switch (MainRoots->case_solution){
        
        case One_Root_Zero_D:
            printf(PURPLE_TEXT ORANGE_BG"The equation has 2 roots, but they are same: x = %lg\n"CLEAR, MainRoots->x_for_zero_D);
            break;

        case Two_Roots:
            printf(PURPLE_TEXT ORANGE_BG"The equation has 2 roots:\nx1 = %lg\tx2 = %lg\n"CLEAR, MainRoots->x1, MainRoots->x2);
            break;

        case One_Root_Zero_A:
            printf(PURPLE_TEXT ORANGE_BG"The equation has 1 root:\nx = %lg\n"CLEAR, MainRoots->x_for_zero_a);
            break;

        case No_Roots:
            printf(PURPLE_TEXT ORANGE_BG"No roots\n"CLEAR);
            break;

        case Infinite_Number_Of_Roots:
            printf(PURPLE_TEXT ORANGE_BG"Infinite number of roots\n"CLEAR);
            break;

        case No_Root_In_Real_Numbers:
            printf(PURPLE_TEXT ORANGE_BG"No roots in real numbers\n"CLEAR);
            printf(PURPLE_TEXT ORANGE_BG"The equation has 2 complex roots:\nx1 = %lg + %lgi\tx2 = %lg - %lgi\n"CLEAR, \
                MainRoots->x1_real_part, MainRoots->x1_imagine_part, MainRoots->x1_real_part, MainRoots->x1_imagine_part);
            break;

    }
}



// __VA_ARGS__ 