/**
 * @file MyAssert.h
 * @brief Need for debug
*/

#ifndef MYASSERT_H_
#define MYASSERT_H_
#include <stdio.h>
#include <stdlib.h>
//#define STOPMYASSERT                          // Отключение ассертов

#ifndef STOPMYASSERT

/// @brief Checking the assertion
#define MyAssert(Bool) if(Bool == 0)\
{\
    do{\
    printf("Error in file %s in line %d", __FILE__, __LINE__);\
    abort();\
    }while(0);\
}
#else
    #define MyAssert(Bool)
#endif

#endif