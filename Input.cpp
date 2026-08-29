//  ВВОД

#include "Input.h"

#define MAKECHAR(sym) #sym[0]

//  Макрос для общего вызова Input
#define SAFEINPUT(coefficient) Input(&(coeffs->coefficient), MAKECHAR(coefficient))

/// @brief This function is called in main to start input
/// @param coeffs Pointer to the coefficients that will be changed
void MainInput(Coefficients* coeffs){
    PrintInput();   // "Введи коэфы пж"
    SAFEINPUT(a);
    SAFEINPUT(b);
    SAFEINPUT(c);
}

/// @brief Input of each coefficient
/// @param coeff Pointer to each coefficient
/// @param sym char symbol of coefficient
void Input(double* coeff, char sym){
    printf(PURPLE_TEXT ORANGE_BG "Enter %c-coefficient:\n" CLEAR, sym);

    while(FuncScanf(coeff) != SUCCESS);
}

/// @brief Cleaning the buffer
void BufferClean(){
    char c = 0;
    while((c = (char)getchar()) != '\n');
    //printf("3\n");
}

/// @brief Printing start text
void PrintInput(){
    printf(PURPLE_TEXT ORANGE_BG "# Solving square equations: ax^2 + bx + c = 0\n" CLEAR);
    printf(PURPLE_TEXT ORANGE_BG "# (c) MIM \n" CLEAR);
    printf(PURPLE_TEXT ORANGE_BG "# Enter a, b, c:\n" CLEAR);
}

/// @brief Entering coefficient with checking for erroneous input
/// @param coeff Each coefficient
/// @return ERRROR - program exits with an error\
/// @return SUCCESS - program completed successfully
Error_or_Success FuncScanf(double* coeff){
    if(scanf("%lg", coeff) != 1){
        printf(PURPLE_TEXT ORANGE_BG "You've made a mistake entering, please try again:\n" CLEAR);
        BufferClean();
        return ERRROR;
    }
    //printf("1\n");
    while(1){
        char c = (char)getchar();
        if(c == ' ' || c == '\t'){
            continue;
        }
        else if(c == '\n'){
            return SUCCESS;
        }
        else{
            printf(PURPLE_TEXT ORANGE_BG "You've made a mistake entering, please try again:\n" CLEAR);
            BufferClean();
            return ERRROR;
        }
    }
}