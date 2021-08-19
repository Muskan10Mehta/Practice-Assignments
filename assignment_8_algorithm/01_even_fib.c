/**
 * Program to print n numbers in Fibonacci series that are even
 *
 * Compilation: gcc -o even_fib 01_even_fib.c
 * Execution: ./even_fib
 *
 * @Muskan, 1910990681, 19/08/2021
 * Assignment 8 Algorithm, Question 1
 */

#include <stdio.h>

int fib(int n){
   if(n == 0 || n == 1){
      return n;
   }

   return fib(n - 1) + fib(n - 2);
}

int main(){

   int n;
   int i = 0;
   int f;
   int counter = 0;

   printf("Enter the n for fibonacci series: ");
   scanf("%d", &n);

   while(counter <= n){
       
       f = fib(i);
       if(f% 2 == 0){
	   printf("%d " , f);
	   counter++; 
       }
       i++;
   }

   printf("\n");

   return 0;
}
