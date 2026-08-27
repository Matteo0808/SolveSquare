#include "Test.h"

int RunMainTest(){
    
    Equation ExpectedEquation[MAX] = {};
    Equation TestEquation[MAX] = {};
    int size = (sizeof(ExpectedEquation) / sizeof(Equation));
    if(OpenTestFile(, size) != SUCCESS){
        //printf("hui1\n");
        return ERRROR;
    }

    // for(int i = 0; i < MAX; i++){
    //     printf("a = %lg \nb = %lg \nc = %lg \ncase = %d \nx1 = %lg \nx2 = %lg \nxa = %lg \nxd = %lg \nx1r = %lg \nx1i = %lg\n\n\n",
    //                 ExpectedEquation[i].a, ExpectedEquation[i].b,
    //                 ExpectedEquation[i].c, ExpectedEquation[i].case_solution,
    //                 ExpectedEquation[i].x1, ExpectedEquation[i].x2,
    //                 ExpectedEquation[i].x_for_zero_a, ExpectedEquation[i].x_for_zero_D, 
    //                 ExpectedEquation[i].x1_real_part, ExpectedEquation[i].x1_imagine_part);
    // }
    
    int count = 0;

    for(int i = 0; i < size; ++i){
        MyAssert(i >= 0 && i < size);
        //printf("i = %d\n", i);
        count += RunTest(ExpectedEquation[i], TestEquation[i]);
        //printf("count = %d\n", count);
    }

    if(count != 0){
        //printf("hui2\n");
        return ERRROR;
    }
    
    return SUCCESS;
}

int RunTest(Equation ExpectedEquation, Equation TestEquation){
    TestEquation.case_solution = SolveSquare(ExpectedEquation.coeffs, &(TestEquation.roots));
    // printf("a = %lg \nb = %lg \nc = %lg \ncase = %d \nx1 = %lg \nx2 = %lg \nxa = %lg \nxd = %lg \nx1r = %lg \nx1i = %lg\n\n\n", ExpectedEquation.a, ExpectedEquation.b,
    //                 ExpectedEquation.c, ExpectedEquation.case_solution,
    //                 ExpectedEquation.x1, ExpectedEquation.x2,
    //                 ExpectedEquation.x_for_zero_a, ExpectedEquation.x_for_zero_D, 
    //                 ExpectedEquation.x1_real_part, ExpectedEquation.x1_imagine_part);
    
    if(TestEquation.case_solution == ExpectedEquation.case_solution &&
        TestEquation.x1 == ExpectedEquation.x1 &&
        TestEquation.x2 == ExpectedEquation.x2 &&
        TestEquation.x_for_zero_a == ExpectedEquation.x_for_zero_a &&
        TestEquation.x_for_zero_D == ExpectedEquation.x_for_zero_D &&
        TestEquation.x1_imagine_part == ExpectedEquation.x1_imagine_part &&
        TestEquation.x1_real_part == ExpectedEquation.x1_real_part){
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
int OpenTestFile(Equation TestEquation[], Equation ExpectedEquation, int size){
    FILE *fp = fopen("Reference.txt", "r");
    if(fp == 0){
        printf("__FILE__READING__FAILURE__\n");
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