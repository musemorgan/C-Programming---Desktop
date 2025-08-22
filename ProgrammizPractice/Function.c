#include <stdio.h>
#include <math.h>
/*Program purpose:
create a Fuction that takes two numb ers, performs multpilication, and Returns the value*/

int mult(int num1, int num2)
{
    
    int sum = num1 * num2;
    return sum;
}


int main(){
    int result = mult(3,5);
    printf("Result = %d", result);

    return 0;
}
/*
Notes:
1. since there is no value input from the user, the parameters in the main program can be the values 
you want to use*/