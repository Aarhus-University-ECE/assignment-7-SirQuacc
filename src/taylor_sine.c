#include "taylor_sine.h"
#include <assert.h>
#include <math.h>


long factorial(int in) {
    assert(in > -1);
    long fact = 1;
    for (int i = 1; i <= in; i++) {
        fact *= i;
    }
    return fact;
}

double taylor_sine(double x, int n)
{
    double sine = 0;
    int swapCount = 0;
    for (int i = 1; swapCount <= n; i+=2){
        if(swapCount%2 == 0){ //even swapCount, when the next bit is added to the previous
            sine += pow(x, i)/factorial(i);
            swapCount++;
        }
        else{ //uneven swapCount, when the next bit is subtracted from the previous
            sine -= pow(x, i)/factorial(i);
            swapCount++;
        }
       // printf("Factorial now: %ld\n", factorial(i));
    }
    
    return sine;
}
