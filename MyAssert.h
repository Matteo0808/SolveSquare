#ifndef MYASSERT_H_
#define MYASSERT_H_

#include <stdio.h>
#include <stdlib.h>

void MyAssert(int Bool);

// assert
void MyAssert(int Bool){
    if(Bool == 1){
        perror("ERROR");
        printf("Error in line %d", __LINE__);
        abort();
    }
}

#endif