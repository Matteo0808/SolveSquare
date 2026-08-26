#include "Input.h"

#define MAXSIZEARRCOEFFS 3
#define MAKECHAR(sym) #sym[0]
#define SAFEINPUT(coefficient) if(Input(&MainRoots->coefficient, MAKECHAR(coefficient)) != SUCCESS){abort();}
//  Ввод

void MainInput(Roots *MainRoots){
    PrintInput();
    SAFEINPUT(a);
    SAFEINPUT(b);
    SAFEINPUT(c);
    //printf("%lg %lg %lg\n", MainRoots->a, MainRoots->b, MainRoots->c);
}

int Input(double* coeff, char sym){
    unsigned short test = 0;
    printf(PURPLE_TEXT ORANGE_BG"Enter %c-coefficient:\n"CLEAR, sym);
    char c = 0;
    int SlavikKleukin = 6;
    while(SlavikKleukin != 0){
        
        if(scanf("%lg", coeff) == 1){
            
            if((c = getchar()) != '\n'){
                printf(PURPLE_TEXT ORANGE_BG"You've made a mistake entering, please try again:\n"CLEAR);
                FuncClear();
            }

            else{
                SlavikKleukin = 0;
            }

        }
        
        else{
            printf(PURPLE_TEXT ORANGE_BG"You've made a mistake entering, please try again:\n"CLEAR);
            FuncClear();
        }

    }

    return SUCCESS;
}

void FuncClear(){
    char c = 0;
    while((c = getchar()) != '\n');
}

void PrintInput(){
    printf(PURPLE_TEXT ORANGE_BG"# Solving square equations: ax^2 + bx + c = 0\n");
    printf(PURPLE_TEXT ORANGE_BG"# (c) MIM \n"CLEAR);
    printf(PURPLE_TEXT ORANGE_BG"# Enter a, b, c:\n"CLEAR);
}