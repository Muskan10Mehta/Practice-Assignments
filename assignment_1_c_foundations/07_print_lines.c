/**
 * Program to input a text file and print lines that are longer than 80 characters
 *
 * Complilation: gcc -o file 07_print_lines.c
 * Execution: ./file
 *
 * @Muskan, 1910990681, 29 July 2021
 * Assignment 1 C Foundations Question 7
 *
 */

#include <stdio.h>

int main(){
   
   FILE *f = fopen("07_text.txt", "r");

   if(f == NULL){
   
       printf("File not found");

   } else{

       char file[100], 


   }

   fclose(f);
   
   return 0;
}
