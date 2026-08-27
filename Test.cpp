// Тестировка программы

#include "Test.h"

//  Запуск тестировки 
int RunMainTest(){
    
    Equation ExpectedEquation[MAX] = {};
    Equation TestEquation[MAX] = {};

    int size = (sizeof(ExpectedEquation) / sizeof(Equation)); //  Размер массива

    if(OpenTestFile(TestEquation, ExpectedEquation, size) != SUCCESS){      //  Считывание тестовых значений из файла
        //printf("hui1\n");
        return ERRROR; //  Ошибка считывания
    }

    // for(int i = 0; i < MAX; i++){
    //     printf("a = %lg \nb = %lg \nc = %lg \ncase = %d \nx1 = %lg \nx2 = %lg \nxa = %lg \nxd = %lg \nx1r = %lg \nx1i = %lg\n\n\n",
    //                 TestEquation[i].coeffs.a, TestEquation[i].coeffs.b,
    //                 TestEquation[i].coeffs.c, ExpectedEquation[i].roots.case_solution,
    //                 ExpectedEquation[i].roots.x1, ExpectedEquation[i].roots.x2,
    //                 ExpectedEquation[i].roots.x_for_zero_a, ExpectedEquation[i].roots.x_for_zero_D, 
    //                 ExpectedEquation[i].roots.x1_real_part, ExpectedEquation[i].roots.x1_imagine_part);          //  Дебаг
    // }
    
    int count = 0; //  Счетчик ошибок выполнения тестов, должен остаться равен нулю

    for(int i = 0; i < size; ++i){
        MyAssert(i >= 0 && i < size);
        //printf("i = %d\n", i);
        count += RunTest(ExpectedEquation[i], TestEquation[i]);
        printf("count = %d\n", count);
    }

    if(count != 0){
        //printf("hui2\n");
        return ERRROR;
    }
    return SUCCESS;
}

//  Запуск каждого теста
int RunTest(Equation ExpectedEquation, Equation TestEquation){
    TestEquation.roots.case_solution = SolveSquare(ExpectedEquation.coeffs, &(TestEquation.roots));
    printf("case = %d \nx1 = %lg \nx2 = %lg \nxa = %lg \nxd = %lg \nx1r = %lg \nx1i = %lg\n\n\n",
                    ExpectedEquation.roots.case_solution,
                    ExpectedEquation.roots.x1, ExpectedEquation.roots.x2,
                    ExpectedEquation.roots.x_for_zero_a, ExpectedEquation.roots.x_for_zero_D, 
                    ExpectedEquation.roots.x1_real_part, ExpectedEquation.roots.x1_imagine_part);
    printf("a = %lg \nb = %lg \nc = %lg \ncase = %d \nx1 = %lg \nx2 = %lg \nxa = %lg \nxd = %lg \nx1r = %lg \nx1i = %lg\n\n\n",
                    TestEquation.coeffs.a, TestEquation.coeffs.b, TestEquation.coeffs.c,
                    TestEquation.roots.case_solution,
                    TestEquation.roots.x1, TestEquation.roots.x2,
                    TestEquation.roots.x_for_zero_a, TestEquation.roots.x_for_zero_D, 
                    TestEquation.roots.x1_real_part, TestEquation.roots.x1_imagine_part);                 //  Дебаг
    
    if(TestEquation.roots.case_solution == ExpectedEquation.roots.case_solution &&
        TestEquation.roots.x1 == ExpectedEquation.roots.x1 &&
        TestEquation.roots.x2 == ExpectedEquation.roots.x2 &&
        TestEquation.roots.x_for_zero_a == ExpectedEquation.roots.x_for_zero_a &&
        TestEquation.roots.x_for_zero_D == ExpectedEquation.roots.x_for_zero_D &&
        TestEquation.roots.x1_imagine_part == ExpectedEquation.roots.x1_imagine_part &&
        TestEquation.roots.x1_real_part == ExpectedEquation.roots.x1_real_part){
        return SUCCESS;
    }
    return ERRROR;
}
/*

int func() {
    if (!sleep())
        if (at_home())
            if (!hungry())
                botat();
            else
                eat();
        else
            go_home();
    else
        wake_up();

    return 0;
}

int func() {
    if (sleep())
        wake_up();
        return 0;

    if (!at_home())
        go_home();
        return 0;

    if (hungry())
        eat();
        return 0;

    botat();
}
*/

//  Считывание тестовых значений из файла
int OpenTestFile(Equation TestEquation[], Equation ExpectedEquation[], int size){
    FILE *fp = fopen("Reference.txt", "r");
    if(fp == 0){
        printf(WHITE_TEXT RED_BG "__FILE__READING__FAILURE__\n" CLEAR);
        return ERRROR;
    }
    for(int i = 0; i < size; ++i){
        MyAssert(i >= 0 && i < size);

        fscanf(fp, "%lg %lg %lg %d %lg %lg %lg %lg %lg %lg", 
            &(TestEquation[i].coeffs.a), &(TestEquation[i].coeffs.b), &(TestEquation[i].coeffs.c), 
            &(ExpectedEquation[i].roots.case_solution),
            &(ExpectedEquation[i].roots.x1), &(ExpectedEquation[i].roots.x2),
            &(ExpectedEquation[i].roots.x_for_zero_a), &(ExpectedEquation[i].roots.x_for_zero_D), 
            &(ExpectedEquation[i].roots.x1_real_part), &(ExpectedEquation[i].roots.x1_imagine_part));
    }
    fclose(fp);
    return SUCCESS;
}