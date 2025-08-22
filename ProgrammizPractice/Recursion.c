#include <stdio.h>
#include <math.h>
/*Program Purpose:
1. create a program that computes the factorial of a number
2. take input
3. pass input to function
4. check if the number is greater than  zero in the function
5. if true, return number multiplied by a recursive call with paramter 1 less than number
6. otherwise, return 1
*/
int factor (int input);

int main(){
int userInput, result;
//double paramMinusOne;
printf("Insert Value: ");
scanf("%d", &userInput);
result = factor(userInput);
printf("Result: %d", result);
return 0;
}

int factor (int input)
{
    if (input <= 0){
        return 1;
    }
        else{
        return input * factor(input-1);
        }
/*
Notes:
1. The recursion section seems like it always goes through the if and the else section. If you
place an error message in the if section, it will print that and the result. So bypass placing an
error message and the outcome will just be zero if it could properly compute. If anything, place an 
if statement in the main program to see if the return was 0, then make an error message for that 
output if needed. but its not required here. */
}