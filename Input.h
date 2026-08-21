#include <stdio.h>

#ifndef INPUT_H_
    #define INPUT_H_
    void Input(double* coeff, char sym);

    void Input(double* coeff, char sym){
        int test = 0;
        printf("Enter %c-coefficient:\n", sym);
        test = scanf("%lg", coeff);
        while(test != 1){
            printf("You've made a mistake entering, please try again:\n");
            scanf("%*c");
            test = scanf("%lg", coeff);
        }
    }
#endif