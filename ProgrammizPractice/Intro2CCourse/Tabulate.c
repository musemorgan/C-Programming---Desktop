/*Create a command line utility that tabulates the letters in all words (which do not have to be
valid English words) supplied as arguments and prints out the number of each letter in the
whole list. All words will be of length 1–128, in lower-case ASCII letters, and there will be no
more than 255 of them.
Example usages:
$ ./tabulate
$ ./tabulate bat cat dog
A 2
B 1
C 1
D 1
G 1
O 1
T 2*/

/*
needs:
1. take arguments as input (pointer? or just params?)
2. adjustable array to store input
3. only take lowercase
4. no more than 255 words *
*/
#include <stdio.h>
//INCOMPLETE

int main(int argc, char* argv[]) {
    // Check if at least one argument (excluding the program name) is provided
    if (argc > 1) 
    {
        int i;
        for (i=0; i<argc; i++);
        {
            char myString[] = argv;

            int check = *myString;
            for (int j = 0; myString[j]== NULL; *(myString + j))
            {  
               printf("%c\n", myString[j]);
            }
        } 
    }
    else 
    {
        printf("No command-line arguments provided.\n");
    
    }
    return 0;
}

