//  ВВОД

#include "Input.h"

//  Переделка в символ
#define MAKECHAR(sym) #sym[0]

//  Макрос для общего вызова Input
#define SAFEINPUT(coefficient) Input(&(coeffs->coefficient), MAKECHAR(coefficient))

//  Главный ввод
void MainInput(Coefficients* coeffs){
    PrintInput();   // "Введи коэфы пж"
    SAFEINPUT(a);
    SAFEINPUT(b);
    SAFEINPUT(c);
    //printf("%lg %lg %lg\n", coeffs->a, coeffs->b, coeffs->c);
}

//  Ввод
void Input(double* coeff, char sym){
    printf(PURPLE_TEXT ORANGE_BG "Enter %c-coefficient:\n" CLEAR, sym);

    //unsigned short test = 0; // Для проверки scanf()
    while(FuncScanf(coeff) != SUCCESS);
}

//  Очистка ввода
void BufferClean(){
    char c = 0;
    while((c = (char)getchar()) != '\n');
    //printf("3\n");
}

//  "Введите коэфы пж"
void PrintInput(){
    printf(PURPLE_TEXT ORANGE_BG "# Solving square equations: ax^2 + bx + c = 0\n" CLEAR);
    printf(PURPLE_TEXT ORANGE_BG "# (c) MIM \n" CLEAR);
    printf(PURPLE_TEXT ORANGE_BG "# Enter a, b, c:\n" CLEAR);
}

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