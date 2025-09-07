#include <stdio.h>
//INCOMPLETE
int main() {
    char str[] = "C Programming";
    int length;

    for (length = 0; str[length] != '\0'; length++);

    printf("The length of the string is: %d\n", length);
    return 0;
}