#include <stdio.h>
/*
Project Purpose:
1. store an array with a student total class grades
2. compute the grade gpa by adding all grades
3. divide by total number of subjects
4. print average 
*/
int main(){
int sum = 0;
int count = 0;


int MorganAverageGpa[5] = {98,72,51,87,90};
for(int i = 0; i <5; i++){
    int gpa = MorganAverageGpa[i];
    count++;
    sum = gpa + sum;
   
    printf("Class %d Grade: %d | Total GPA:%d\n", i + 1, gpa, sum / count);
}

printf ("Final Test Average: %d", sum/count);






    return 0;
}