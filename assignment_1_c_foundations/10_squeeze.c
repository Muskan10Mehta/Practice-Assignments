/**
 * Program to create a function squeeze that deletes each character in string 1 that matches any character in string 2
 *
 * Complilation: gcc -o squeeze 10_squeeze.c
 * Execution: ./squeeze
 *
 * @Muskan, 1910990681, 29 July 2021
 * Assignment 1 C Foundations Question 10
 */
#include <stdio.h>

void squeeze(char*, char*);

int main(){
   
   char s1[50];
   char s2[50];

   printf("Enter first string: ");
   scanf("%s", s1);

   printf("Enter second string: ");
   scanf("%s", s2);

   squeeze(s1, s2);

   printf("Squeezed string: %s\n", s1);
      
   return 0;
}

void squeeze(char s1[], char s2[]){
    
   int i, j, k, w;

   for(i = 0; s1[i]; i++){
       
	for( j = 0; s1[j]; j++){
	   for(k = 0; s2[k]; k++){
	      if(s1[j] == s2[k]){
	         for(w = j; s1[w]; w++){
		    s1[w] = s1[w + 1];
		 } 
	      }
	   
	   }
	
	}
   
   }
}
