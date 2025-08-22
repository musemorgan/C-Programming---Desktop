#include <stdio.h>
// Incomplete
int main(){
double salary;
double* ptr = &salary;

printf("Input Salary: ");
scanf("%lf", ptr);
printf("%p", *ptr);





    return 0;
}