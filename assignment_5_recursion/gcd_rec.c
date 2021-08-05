/**
 * Program to compute greatest common factor of two numbers
 *
 * Complilation: gcc -o gcd gcd_rec.c
 * Execution: ./gcd
 *
 * @Muskan, 1910990681, 4/8/2021
 * Assignment 5 Recursion Foundations Question 2 
 */

#include <stdio.h>

int gcd(int, int);

int main(){
   
   int number;
   int number2;
   int res;

   printf("Enter first number: ");
   scanf("%d", &number);

   printf("Enter second number: ");
   scanf("%d", &number);

   res = gcd(number, number2);

   printf("%d\n", res);
   
   return 0;
}


/**
 * Function to get the gcd of two numbers
 *
 * Parameters:
 * a : first integer number
 * b : second integer number
 *
 * this function uses Euclidean Algorithm for gcd, according to which if we subtract a smaller number from a larger one, gcd doesn't change
 * so here we are reducing one number by using modulus until one number becomes zero
 * when it does the other will become the gcd
 * 
 * if one number is zero then the other non-zero number becomes the gcd since anything * zero is zero which means it divides everything 
 * so we countinously mod one number with the result of the previous mod until it comes down to 0
 *
 * returns: gcd
 */

int gcd(int a, int b){

if(b == 0){
     return a;
}
 return gcd(b, a % b);
}
