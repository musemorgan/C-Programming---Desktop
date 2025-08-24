#include <stdio.h>
/*
Project Purpose:
1. takes input from a double variable salary
2. Assigns the address of a salary to a double pointer
3. uses the pointer to print the salary, increase the salary, and print the new salary*/
int main(){
double salary;
double* ptr = &salary;
printf("Insert Salary: ");
scanf("%lf", &salary); // Use the address when pulling a value using scan
printf("\nSalary = %.2lf", *ptr); //Use the pointer itself to point to the value within the address used above
*ptr = salary * 2;
printf("\nNew Salary = %.2lf", *ptr);







    return 0;
}