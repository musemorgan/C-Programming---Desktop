#include <stdio.h>

int main(){
/*Program Purpose: Create a program that takes input and prints the value if:
1. it is a negative odd number
2. skip printing the value if it is negative even, but still continue the loop and print "Negative Even"
3. exit the loop if it is positive, end off with "positive value"*/

while (1){ //while(1) evaluates to true even without the bool library
    int userInput;
    printf("Insert Value: ");
    scanf("%d", &userInput);

            //Positive value
        if (userInput % 2 == 0 && userInput > 0)
            {
                printf("Positive Value");
                break;
            }
                //Negative Even
        else if (userInput < 0 && userInput % 2 ==0)
            {
            printf("Negative Even\n");
            continue;
            }
    {
        printf("\n%d \n", userInput);
    }
            
}
/*
Notes:
1. STOP FORGETTING THE & IN THE SCANF PARANTHESIS!!
*/
    return 0;
}