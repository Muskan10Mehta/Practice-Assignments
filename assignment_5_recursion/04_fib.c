/**
 * Program to print every third element of the fibonacci series
 *
 * Complilation: gcc -o fib fibonacci_three.c
 * Execution: ./fib
 *
 * @Muskan, 1910990681, 4/8/2021
 * Assignment 5 Recursion Question 4 
 */

#include <stdio.h>

int fib(int);

int main(){
   
   int n;
   int i;

   printf("Enter the number of outputs required: ");
   scanf("%d", &n);
   
   printf("For n = %d: ", n);

   // upper limit is 3 * n so it can accomodate n number every third number
   // i starts from index 3 and find fibonacci number for indcies i + 3
   
   for(i = 3; i <= 3 * n; i += 3){
     printf("%d ", fib(i));
   
   } 

   printf("\n");

   return 0;
}


/**
 * Function to calulate the fibonacci number at index n
 * 
 * Parameters: 
 * n : index of number in fibonacci series
 *
 * returns: number at index n
 */

int fib(int n){
   
   if(n == 1 || n == 0){
     return n;
   }

   return fib(n - 1) + fib(n - 2);
}
