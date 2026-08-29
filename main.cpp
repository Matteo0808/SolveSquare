#include <stdio.h>
#include <math.h>
//#define NDEBUG
//#include <assert.h>
#include <stdlib.h>

#include "MyAssert.h"

#include "MyMath.h"
#include "MyMath.cpp"

#include "Input.h"
#include "Input.cpp"

#include "Const.h"

#include "Test.h"
#include "Test.cpp"

int main(){
    
    // TODO: исправить пробелы, переисать int на Case, исправить ифы, переделать solve нахуй
    // ask: abort(), разделение структуры, про потоки _thread_local и _Atomic 
    // learn: __VA_ARGS__, malloc(), calloc(), free()

    // for(int i = 0; i < 256; i++){
    //     printf("%d = %c\n", i, i);                       //     All chars
    // }
    // return 0;
    
    struct Equation MainEquation = {}; //   Все параменты квадратки

    // Тест
    if(RunMainTest() != SUCCESS)
    {
        printf(WHITE_TEXT RED_BG "__TESTS__FAILED__" CLEAR "_\n");
        return ERRROR; //   Завершение программы
    }
    else{
        printf(WHITE_TEXT GREEN_BG "__TESTS__COMPLETED__SUCCESSFULLY__" CLEAR "_\n");
    }

    //  Ввод
    MainInput(&(MainEquation.coeffs));

    //  Решение
    MainEquation.roots.case_solution = SolveSquare(MainEquation.coeffs, &(MainEquation.roots));

    //  Ответ
    Answer(MainEquation.roots);
    
    return SUCCESS;
}