#include <stdio.h>
/*
Purpose:
1. Finds the largest element in the array
2. assign the first element to the pointer 
3. loops to access each element
4. compares largest to each array element
5. then replaces or moves on to the next value*/
int main(){

int arr[] = {34,12,21,54,48};
int largest = *arr;

for (int i =0; i<5;i++)
{
    int result = largest > *(arr+i);
        if(result != 0){
        continue;
        }
        else 
        {
        largest = *(arr+i);
        continue;
        }
}
printf("The largest value = %d", largest);

    return 0;
}