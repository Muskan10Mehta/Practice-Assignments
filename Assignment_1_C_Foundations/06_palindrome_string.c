/**
 * Program to check if the given string is palindrome or not
 *
 * Compilation: gcc -o palindrome palindrome_string.c
 * Execution: ./palindrome
 *
 * @Muskan, 190990681, 28/07/2021
 * Day 2 Assignment C Foundations, Question 7
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
   
   //to calculate string length
   for(i = 0; input[i]; i++){
       length++;
   }
   
   // checks whether the first chracter matches with the last
   // to ingore case of chracter we change the last digit to lowercase or to uppercase
   // lowercase starts from a = 97, uppercase starts from A = 65
   if( input[0] == input[length-1]|| input[0] == input[length-1] + 32 || input[0] == input[length-1] - 32){
	printf("true\n");
   } else{
	printf("false\n");
   }


   return 0;
}

