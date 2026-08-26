#include "Test.h"

int RunMainTest(){
    
    struct Roots ExpectedRoots[];
    int size = (sizeof(ExpectedRoots) / sizeof(Roots));
    if(OpenTestFile(ExpectedRoots, size) != SUCCESS){
        //printf("hui1\n");
        return ERRROR;
    }

    // for(int i = 0; i < MAX; i++){
    //     printf("a = %lg \nb = %lg \nc = %lg \ncase = %d \nx1 = %lg \nx2 = %lg \nxa = %lg \nxd = %lg \nx1r = %lg \nx1i = %lg\n\n\n",
    //                 ExpectedRoots[i].a, ExpectedRoots[i].b,
    //                 ExpectedRoots[i].c, ExpectedRoots[i].case_solution,
    //                 ExpectedRoots[i].x1, ExpectedRoots[i].x2,
    //                 ExpectedRoots[i].x_for_zero_a, ExpectedRoots[i].x_for_zero_D, 
    //                 ExpectedRoots[i].x1_real_part, ExpectedRoots[i].x1_imagine_part);
    // }
    
    int count = 0;

    for(int i = 0; i < MAX; ++i){
        MyAssert(i >= 0 && i < MAX);
        //printf("i = %d\n", i);
        count += RunTest(ExpectedRoots[i]);
        //printf("count = %d\n", count);
    }

    if(count != 0){
        //printf("hui2\n");
        return ERRROR;
    }
    
    return SUCCESS;
}

int RunTest(Roots ExpectedRoots){
    Roots TestRoots = {ExpectedRoots.a, ExpectedRoots.b, ExpectedRoots.c, 0, 0, 0, 0, 0, 0, 0};
    TestRoots.case_solution = SolveSquare(&TestRoots);
    // printf("a = %lg \nb = %lg \nc = %lg \ncase = %d \nx1 = %lg \nx2 = %lg \nxa = %lg \nxd = %lg \nx1r = %lg \nx1i = %lg\n\n\n", ExpectedRoots.a, ExpectedRoots.b,
    //                 ExpectedRoots.c, ExpectedRoots.case_solution,
    //                 ExpectedRoots.x1, ExpectedRoots.x2,
    //                 ExpectedRoots.x_for_zero_a, ExpectedRoots.x_for_zero_D, 
    //                 ExpectedRoots.x1_real_part, ExpectedRoots.x1_imagine_part);
    
    if(TestRoots.case_solution == ExpectedRoots.case_solution &&
        TestRoots.x1 == ExpectedRoots.x1 &&
        TestRoots.x2 == ExpectedRoots.x2 &&
        TestRoots.x_for_zero_a == ExpectedRoots.x_for_zero_a &&
        TestRoots.x_for_zero_D == ExpectedRoots.x_for_zero_D &&
        TestRoots.x1_imagine_part == ExpectedRoots.x1_imagine_part &&
        TestRoots.x1_real_part == ExpectedRoots.x1_real_part){
        return SUCCESS;
    }

    return ERRROR;
}

int OpenTestFile(Roots ExpectedRoots[], int size){
    MyAssert(ExpectedRoots);
    FILE *fp = fopen("Coefficients.txt", "r");
    if(fp != 0){
        for(int i = 0; i< size-1; ++i){
            fscanf(fp, "%lg %lg %lg %d %lg %lg %lg %lg %lg %lg", 
                    &ExpectedRoots[i].a, &ExpectedRoots[i].b,
                    &ExpectedRoots[i].c, &ExpectedRoots[i].case_solution,
                    &ExpectedRoots[i].x1, &ExpectedRoots[i].x2,
                    &ExpectedRoots[i].x_for_zero_a, &ExpectedRoots[i].x_for_zero_D, 
                    &ExpectedRoots[i].x1_real_part, &ExpectedRoots[i].x1_imagine_part);
        }
        fclose(fp);
        return SUCCESS;
    }
    else{
        printf("__FILE__READING__FAILURE__\n");
        return ERRROR;
    }
}