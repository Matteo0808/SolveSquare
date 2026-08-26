#include <stdio.h>
#include <math.h>
//#define NDEBUG
#include <assert.h>
#include <stdlib.h>

#include "MyAssert.h"

#include "MyMath.h"
#include "Input.h"
#include "Const.h"
#include "Test.h"

int main(){
    
    // TODO: исправить пробелы, переисать int на Case, исправить ифы, warnings, new sruct, переделать solve нахуй

    struct Equation MainEquation = {};
    if(RunMainTest() != SUCCESS)
    {
        printf(WHITE_TEXT RED_BG "__TESTS__FAILED__" CLEAR "_\n");
        return ERRROR;
    }
    else{
        printf(WHITE_TEXT GREEN_BG "__TESTS__COMPLETED__SUCCESSFULLY__" CLEAR "_\n");
    }

    MainInput(&MainRoots);
    MainRoots.case_solution = SolveSquare(&MainRoots);

    Answer(&MainRoots);
    
    return SUCCESS;
}