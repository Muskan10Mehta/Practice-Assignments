/**
 * Program to print a pyramid for a given number of steps/rows
 *
 * Compilation: gcc -o pyramid hash_pyramid.c
 * Execution: ./pyramid
 *
 * @Muskan, 190990681, 28/07/2021
 */

#include <stdio.h>

void pyramid(int);

int main(){
   
   int steps; // number of steps for pyramids

   printf("Enter number of steps for pyramid: ");
   scanf("%d", &steps);

   pyramid(steps);

   return 0;
}

/** Function to build the pyramid
 * 
 * Paramters: 
 * steps: integer number of steps for pyramid
 * prints the pyramid
 */

void pyramid(int steps){
     
   int i, j; //for loops
   int top; //top position of the pyramid

   // to make a pyramid there must be spaces after each hash
   // hence double the number of steps 
   top = (steps*2)/2; 
   j=0;
   
   while(steps--){
   
   // white spaces on left decreses with increase in steps
   for(i = 0; i < top; i++){
       printf(" ");
   }
   top--;

   for(i = 0; i<= j; i++){
       printf("# ");
   }
   j++;

   printf("\n");

   }
}
