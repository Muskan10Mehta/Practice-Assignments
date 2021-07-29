/**
 * Program to swap two numbers without using a third variable
 *
 * Compilation: gcc -o swap swap.c
 * Execution: ./swap.c
 *
 * @Muskan, 1910990681, 24/07/2021
 * Assignment 1 - C Foundations : Problem 1 
 */

#include <stdio.h>

void swap(int*, int*);

int main(){

   //declaring integer variables
   int a;
   int b;
   
   //scanning the user input for variable a and b
   printf("Enter first number: ");
   scanf("%d", &a);
   printf("Enter second number: ");
   scanf("%d", &b);

   //sending values to swap function
   swap(&a,&b);

   printf("Swapped a = %d b = %d\n", a, b);
}

/**
 * Function to swap two integer numbers without using a third variable
 *
 * Parameters: 
 * a: integer number to be swapped
 * b: integer number to be swapped
 */

void swap(int *a, int *b){
   
   // swapping a and b by the logic :: eg a = 15 b = 5
   // add both numbers in a :: a = 15 
   // subtract b from a and assign to b; now b has value of a :: b = a - b; b = 10;
   // subtract b from a again and assign to a; now a has value of b :: a = a - b; a = 5;

   *a = *a + *b;
   *b = *a - *b;
   *a = *a - *b;
}
