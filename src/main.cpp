#include <stdio.h>
#include <math.h>
extern "C"
{
#include "stack.h"
#include "taylor_sine.h"
}

// Add your test cases for Exercise 1b,c) here
int main(int argc, char **argv)
{
    /*
     * Own tests for the taylor_sine.c function
     */
    double ownTestCases[5] = {0.03, 2.5, 6, 19, 47};
    int precision[5] = {3, 7, 9, 13, 15};

    for(int i = 0; i < 5; i++){
        for(int i2 = 0; i2 < 5; i2++){
            printf("Test of sine, x=%f, precision=%d, result=%f\nComparted to math function sin(%f): %f\n", ownTestCases[i], precision[i2], taylor_sine(ownTestCases[i], precision[i2]), ownTestCases[i], sin(ownTestCases[i]));
        }
        
    }
    


    return 0;
}