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
    double ownTestCases[5] = {1, 2.5, 6, 19, 47};
    int precision[9] = {2, 4, 7, 9, 13, 21, 69, 83, 420};

    for(int i = 0; i < 5; i++){ //Nested for loops, testing each x value with each of the precision values.
        for(int i2 = 0; i2 < 9; i2++){
            printf("Test of sine, x=%f, precision=%d, result=%f\nComparted to math function sin(%f) = %f\n\n", ownTestCases[i], precision[i2], taylor_sine(ownTestCases[i], precision[i2]), ownTestCases[i], sin(ownTestCases[i]));
        }
    }

    /*
     * The tests above show that a lower value of x (from ownTestCases) is easier to get right even with lower precision.
     * but when x gets higher, if you want any reasonably accurate result, the precision needs to go higher as well.
     * However, if x gets too high, in these tests problems start at 47 where no matter the precision, the result seems 
     * to not be right. Most likely due to some overflow problem.
     * Eventually the precision can also get too high, meaning it will simply produce an error for the result.
     */
    
    return 0;
}