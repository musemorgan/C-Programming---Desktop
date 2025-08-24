#include <stdio.h>
// Incomplete
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