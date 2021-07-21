/**
 * This program computes the square root of a number upto p decimal places using binary search without using any inbuilt functions
 * 
 * Compilation: gcc -o sqaure_root square_root.c
 * Execution: ./square_root.c
 *
 * @Anuinder, 20/07/2021
 * Solution presented in class  
 */

#include <stdio.h>

double square_root_binary_search(double, int);

int main(){
    
    // variables number and precision
    double number = 0;
    int precision = 0;

    printf("Enter number");
    scanf("%lf", &number);
    printf("Enter precision");
    scanf("%d", &precision);

    double sqroot = square_root_binary_search(number, precision);
    printf("%.*lf",precision, sqroot);
     
    return 0;
}

/**
 * Function to compute the root of the number
 *
 * Parameters
 * number: double type number whose square root we are to calculate
 * precision: integer number for decimal precision
 * return the square root in double data type
 */

double square_root_binary_search(double number, int precision){
    
   // calculate the difference
   double difference = 1;
   for(int i = 0; i < precision; i++;) {
   	difference = difference/10;
   {
   
   // bounds for the binary search
   double lower_limit = 0;
   double upper_limit = number;

   // checking for the square root
   // this loop will search the square root with precision not just the integer part
   while((upper_limit - lower_limit) > difference) {
   	double mid = (lower_limit + upper_limit)/2;

	// if square of the mid is less than that number, check the right part
	if (mid * mid <= number){
	    lower_limit = mid;
	} else {
	    upper_limit = mid;
	}
   }

   return lower_limit;
}

