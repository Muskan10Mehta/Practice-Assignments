/**
 * Program to find the rightmost occurence of t in s, returns -1 if there is none
 *
 * Compilation: gcc -o str_index 12_strindex.c
 * Execution: ./str_index
 *
 * @Muskan, 1910990681, 6/8/21
 * Assignment 1 C Foundations, Question 12
 */

#include <stdio.h>

int strlength(char*);
int strindex(char*, char*);

int main(){

   char s1[50];
   char s2[50];

   printf("Enter first string: ");
   scanf("%s", s1);

   printf("Enter second string: ");
   scanf("%s", s2);

   printf("Rightmost occurence of String 2 in String 1:  %d\n", strindex(s1, s2));

   return 0;
}

int strlength(char *s){

   int len;
   int i;

   for(i = 0; s[i]; i++){
       len++;
   }
   
   return len;
}

int strindex(char *s1, char *s2){

  int i, j, k;
  int flag = 0;
  int index = -1;

  for(i = 0; s1[i]; i++){
  
     if(s1[i] == s2[0]){
        
	k = i + 1;
        for(j = 1; s2[j]; j++){
	   
	   if(s1[k] == s2[j]){
	         flag = 1;
	   } else{
	         flag = 0;
		 break;
 	   }
         
	}
	
       if(flag == 1){
           index = i;
       }
     }
  
  }

  return index;
}
