// Тестировка программы

#include "Test.h"

//  Запуск тестировки 
Error_or_Success RunMainTest(){
    
    //  TODO: прочитать про realloc(), переписать массивы под calloc(), ввести переменную init_size
    int init_size = 1;

    Equation* ExpectedEquation = (Equation*) calloc(init_size, sizeof(Equation));
    if(ExpectedEquation == NULL){
        printf(WHITE_TEXT RED_BG "__ERROR__IN__MEMORY_ALLOCATION__" CLEAR "_");
        return ERRROR;
    }

    Equation* TestEquation = (Equation*) calloc(init_size, sizeof(Equation));
    if(TestEquation == NULL){
        printf(WHITE_TEXT RED_BG "__ERROR__IN__MEMORY_ALLOCATION__" CLEAR "_");
        return ERRROR;
    }

    // printEqu(ExpectedEquation, "ExpectedEquation");
    // printEqu(TestEquation, "TestEquation");
    init_size = OpenTestFile(&TestEquation, &ExpectedEquation, init_size);
    //printf("%d\n", init_size);
    for(int i = 0; i < init_size; i++){
        // printEqu(TestEquation[i], "TestEquation");
        // printEqu(ExpectedEquation[i], "ExpectedEquation");
                  //  Дебаг
    }

    if(init_size == ERRROR){      //  Считывание тестовых значений из файла
        //printf("hui1\n");
        printf(WHITE_TEXT RED_BG "__ERROR__IN__MEMORY_ALLOCATION__" CLEAR "_");
        free(ExpectedEquation);
        free(TestEquation);
        return ERRROR; //  Ошибка считывания
    }
    //printf("HUIIIIII\n");
    ExpectedEquation = (Equation* ) realloc(ExpectedEquation, init_size * sizeof(Equation));
    if(ExpectedEquation == NULL){
        printf("Error in ee\n");
        return ERRROR;
    }
    TestEquation = (Equation* ) realloc(TestEquation, init_size * sizeof(Equation));
    if(TestEquation == NULL){
        printf("Error in te\n");
        return ERRROR;
    }


    //printf("PIZDAAAA\n");
    
    int SlavikKleukin = 0; //  Счетчик ошибок выполнения тестов, должен остаться равен нулю

    for(int i = 0; i < init_size; i++){
        MyAssert((i >= 0) && (i < init_size));
        //printf("i = %d\n", i);
        SlavikKleukin += RunTest(ExpectedEquation[i], TestEquation[i]);
        // printEqu(TestEquation[i], "TestEquation");
        // printEqu(ExpectedEquation[i], "ExpectedEquation");
        //printf("SlavikKleukin = %d\n", SlavikKleukin);
    }

    if(SlavikKleukin != 0){
        //printf("hui2\n");
        free(ExpectedEquation);
        free(TestEquation);
        return ERRROR;
    }
    free(ExpectedEquation);
    free(TestEquation);
    return SUCCESS;
}

//  Запуск каждого теста
Error_or_Success RunTest(Equation ExpectedEquation, Equation TestEquation){
    TestEquation.roots.case_solution = SolveSquare(TestEquation.coeffs, &(TestEquation.roots));
    // printf("case = %d \nx1 = %lg \nx2 = %lg \nxa = %lg \nxd = %lg \nx1r = %lg \nx1i = %lg\n\n\n",
    //                 ExpectedEquation.roots.case_solution,
    //                 ExpectedEquation.roots.x1, ExpectedEquation.roots.x2,
    //                 ExpectedEquation.roots.x_for_zero_a, ExpectedEquation.roots.x_for_zero_D, 
    //                 ExpectedEquation.roots.x1_real_part, ExpectedEquation.roots.x1_imagine_part);
    // printf("a = %lg \nb = %lg \nc = %lg \ncase = %d \nx1 = %lg \nx2 = %lg \nxa = %lg \nxd = %lg \nx1r = %lg \nx1i = %lg\n\n\n",
    //                 TestEquation.coeffs.a, TestEquation.coeffs.b, TestEquation.coeffs.c,
    //                 TestEquation.roots.case_solution,
    //                 TestEquation.roots.x1, TestEquation.roots.x2,
    //                 TestEquation.roots.x_for_zero_a, TestEquation.roots.x_for_zero_D, 
    //                 TestEquation.roots.x1_real_part, TestEquation.roots.x1_imagine_part);                 //  Дебаг
    
    if(TestEquation.roots.case_solution == ExpectedEquation.roots.case_solution &&
        IsEqual(TestEquation.roots.x1, ExpectedEquation.roots.x1) &&
        IsEqual(TestEquation.roots.x2, ExpectedEquation.roots.x2) &&
        IsEqual(TestEquation.roots.x_for_zero_a, ExpectedEquation.roots.x_for_zero_a) &&
        IsEqual(TestEquation.roots.x_for_zero_D, ExpectedEquation.roots.x_for_zero_D) &&
        IsEqual(TestEquation.roots.x1_imagine_part, ExpectedEquation.roots.x1_imagine_part) &&
        IsEqual(TestEquation.roots.x1_real_part, ExpectedEquation.roots.x1_real_part)){
        return SUCCESS;
    }
    return ERRROR;
}

//  Считывание тестовых значений из файла
int OpenTestFile(Equation** TestEquation, Equation** ExpectedEquation, int init_size){
    int c = 0;
    FILE *fp = fopen("Reference.txt", "r");
    if(fp == NULL){
        printf(WHITE_TEXT RED_BG "__FILE__READING__FAILURE__\n" CLEAR);
        return 0;
    }

    int GoshaKazunin = 0;
    while(1){
        if(GoshaKazunin == init_size){
            //printf("Realloc: %d -> %d\n", init_size, init_size * 2);
            init_size = init_size * 2;
            *ExpectedEquation = (Equation* ) realloc(*ExpectedEquation, init_size * sizeof(Equation));
            *TestEquation     = (Equation* ) realloc(*TestEquation,     init_size * sizeof(Equation));
            
            if(*TestEquation == NULL || *ExpectedEquation == NULL){
                //printf("hui4\n");
                return ERRROR;
            }
            ReallocNull(*TestEquation,     (init_size / 2) * sizeof(Equation));
            ReallocNull(*ExpectedEquation, (init_size / 2) * sizeof(Equation));
        }
        // puts("Before fscanf\n");
        // printEqu((*TestEquation    )[GoshaKazunin], "TestEquation");
        // printEqu((*ExpectedEquation)[GoshaKazunin], "ExpectedEquation");

        int test = 0;
        test = fscanf(fp, "%lg %lg %lg %d %lg %lg %lg %lg %lg %lg", 
                        &(*TestEquation)[GoshaKazunin].coeffs.a,
                        &(*TestEquation)[GoshaKazunin].coeffs.b,
                        &(*TestEquation)[GoshaKazunin].coeffs.c, 
                        (int* )&(*ExpectedEquation)[GoshaKazunin].roots.case_solution,
                        &(*ExpectedEquation)[GoshaKazunin].roots.x1,
                        &(*ExpectedEquation)[GoshaKazunin].roots.x2,
                        &(*ExpectedEquation)[GoshaKazunin].roots.x_for_zero_a,
                        &(*ExpectedEquation)[GoshaKazunin].roots.x_for_zero_D,
                        &(*ExpectedEquation)[GoshaKazunin].roots.x1_real_part,
                        &(*ExpectedEquation)[GoshaKazunin].roots.x1_imagine_part);
        if (test != 10){
            return ERRROR;
        }
        // puts("After fscanf\n");
        // printEqu((*TestEquation    )[GoshaKazunin], "TestEquation");
        // printEqu((*ExpectedEquation)[GoshaKazunin], "ExpectedEquation");
        
        GoshaKazunin++;
        //printf("Gosha = %d\n\n", GoshaKazunin);
        if((c = fgetc(fp)) == EOF){
            //printf("hui2\n");
            fclose(fp);
            return GoshaKazunin;
        }
    }
}


void printEqu(Equation Equ, char str[]){
    printf("%s:\na = %lg b = %lg c = %lg case = %d x1 = %lg x2 = %lg xa = %lg xd = %lg xreal = %lg xi = %lg\n", str,
                        (Equ.coeffs.a), (Equ.coeffs.b), (Equ.coeffs.c), 
                        (int)(Equ.roots.case_solution),
                        (Equ.roots.x1), (Equ.roots.x2),
                        (Equ.roots.x_for_zero_a), (Equ.roots.x_for_zero_D),
                        (Equ.roots.x1_real_part), (Equ.roots.x1_imagine_part));
}

void ReallocNull(Equation* Equ, int size){
    memset(Equ + size/sizeof(Equation), 0, size );
}
/*

double* a = 0x100;
a += 1;
// a = 108

Equation* equ = 0x100;
equ += size;
// equ = 0x110

*/
