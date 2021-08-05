/**
 * Program that returns the first index in string 1 where any character from string 2 occurs
 * returns -1 if there is no matching character
 *
 * Complilation: gcc -o any 11_any_match.c
 * Execution: ./any
 *
 * @Muskan, 1910990681, 29 July 2021
 * Assignment 1 C Foundations Question 
 */
#include <stdio.h>

int any(char*, char*);

int main(){
   
   char s1[50];
   char s2[50];
   int index;

   printf("Enter first string: ");
   scanf("%s", s1);

   printf("Enter second string: ");
   scanf("%s", s2);
   
   index = any(s1, s2);

   printf("%d\n", index);

   return 0;
}

/** Function to find the first index at which any character from s2 occurs in s1
  * 
  * Parameters: 
  * char array s1
  * char array s2
  *
  * returns index of first occurence, if none returns -1
  */

int any(char s1[], char s2[]){
    
   int i, j;

   for(i = 0; s2[i]; i++){
   	for(j = 0; s1[j]; j++){
	   if(s2[i] == s1[j]){
	         return j; // index of first matched character
		 break;
	   }
	}
   }

   return -1;
}
