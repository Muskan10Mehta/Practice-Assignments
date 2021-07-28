/**
 * Program to count number of vowels and consonants in a given string
 * spaces and special characters are counted as strings
 *
 * Compilation: gcc -o countvc vowels_cons.c
 * Execution: ./countvc
 *
 * @Muskan, 190990681, 28/07/2021
 * Day 2 Assignment C Foundations
 * Resources: geeksforgeeks (I forgot how to take string input with spaces)
 */

#include <stdio.h>
#include <string.h>

/*void count_vowels_consonants(char*, int*, int*);*/
int main(){
   
   char input[100];
   int vowels = 0; // stores vowel count
   int consonants = 0; // stores consonant count
   int i;
   printf("Enter the string for which you want to count vowels and consonants: ");

   //  ^ (XOR) operator gives true until both characters are different 
   //  i.e the input and \n
   //  once character is equal to \n, ^ gives false
   //  hence this scan statement will only scan srting input until newline is encountered 
   //  and we can have string input with spaces that way
   //  simple %s stops taking input once space is encountered 
   scanf("%[^\n]s", input);
   
   for(i = 0; input[i];i++){
        if(input[i] == 'a'|| input[i] == 'A'||input[i] == 'e'||input[i] == 'E'||input[i] == 'i' || input[i] == 'I'||input[i] == 'o'||input[i] == 'O'||input[i] == 'u'||input[i] == 'U'){
           vowels++;
        }else {
           consonants++;
        }

   }

   printf("Vowels = %d, Consonants = %d\n", vowels, consonants);


   return 0;
}

