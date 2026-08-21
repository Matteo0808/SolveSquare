#include <stdio.h>
#include "Const.h"
//  Проверка погрешности
#ifndef CHECKINGNEARZERO_H_
    #define CHECKINGNEARZERO_H_
    int ChekingNearZero(double number);

    int CheckingNearZero(double number){
        if((number - 0) < EPS && (number - 0) > -EPS){
            return 1;
        }
        else{
            return 0;
        }
    }
#endif