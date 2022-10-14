#include "taylor_sine.h"
#include <assert.h>
#include <math.h>


double factorial(int in) { //Double return-type is used to make sure the value can be high enough, even though for this use-case it will only do whole numbers.
    assert(in > -1); //Can't have factorials of negative numbers
    double fact = 1; //start factorial at 1, because 0! = 1
    for (int i = 1; i <= in; i++) { //Calculate the factorial via a for loop, multiplying 1*1*2*3*4*5 until you reach the input number.
        fact *= i;
    }
    return fact;
}

double taylor_sine(double x, int n)
{
    double sine = 0; //Initialize variable to return
    int swapCount = 0; //Keep track of whether to add or subtract from previous result in the for loop.
    for (int i = 1; swapCount <= n; i+=2){
        if(swapCount%2 == 0){ //even swapCount, when the next bit is added to the previous
            sine += pow(x, i)/factorial(i); //Culcalation based on the taylor sine formula
            swapCount++;
        }
        else{ //uneven swapCount, when the next bit is subtracted from the previous
            sine -= pow(x, i)/factorial(i);
            swapCount++;
        }
    }
    return sine;
}
