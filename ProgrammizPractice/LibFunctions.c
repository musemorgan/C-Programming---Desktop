#include <stdio.h>
#include <math.h>
/*Program purpose:
Create a program that computes the result of a number raised to the power of the square root of a number. 
-Take input from user
-Compute square root of a number using library function
-Computer the power of the number raised to the power of its square root
-print
*/
int main(){

    printf("Insert a coefficient: ");
    double coefficient, exponent, result; 
    scanf("%lf", &coefficient);
    exponent = coefficient;
    sqrt(coefficient);
    result = pow(coefficient, exponent);
    printf("Result = %.2lf", result);


/*
Notes:
1. remember that the % and the decimal for data truncation is in front of the data format specification
*/

    return 0;
}