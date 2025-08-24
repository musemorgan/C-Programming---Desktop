#include <stdio.h>

void multiply(int *ptr1, int *ptr2, int *ptr3);

int main(){
int result, value1 = 13, value2 = 9;
int* ptr = &result; //means the value of this pointer is stored at the location of result
multiply(&value1,&value2,&result); //since we are using the address of pointers here, func params needed the pointers itself as seen below
printf("Result: %d", *ptr); // how to print the value of a pointer





    return 0;
}

void multiply(int *ptr1, int *ptr2, int *ptr3)
{
    *ptr3 = *ptr1 * *ptr2;
}
