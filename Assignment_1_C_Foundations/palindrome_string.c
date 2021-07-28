/**
 * Program to check if the given string is palindrome or not
 *
 * Compilation: gcc -o palindrome palindrome_string.c
 * Execution: ./palindrome
 *
 * @Muskan, 190990681, 28/07/2021
 * Day 2 Assignment C Foundations, question 7
 */

#include <stdio.h>
#include <string.h>

int main(){
   
   char input[100];
   int length;
   int i = 0;
   printf("Enter the string to check palindrome: ");

   //  ^ (XOR) operator gives true until both characters are different 
   //  i.e the input and \n
   //  once character is equal to \n, ^ gives false
   //  hence this scan statement will only scan srting input until newline is encountered 
   //  and we can have string input with spaces that way
   //  simple %s stops taking input once space is encountered 
   scanf("%[^\n]s", input);
   
   for(i = 0; input[i]; i++){
       length++;
   }
   
   if( input[0] == input[length-1]|| input[0] == input[length-1] + 32 || input[0] == input[length-1] - 32){
	printf("true\n");
   } else{
	printf("false\n");
   }


   return 0;
}

