/**
 * Program to check if string 2 occurs at the end of string 1
 * returns 1 if there if it does, returns 0 if it doesn't
 *
 * Complilation: gcc -o strend 12_strend.c
 * Execution: ./strend
 *
 * @Muskan, 1910990681, 29 July 2021
 * Assignment 1 C Foundations Question 13 
 */
#include <stdio.h>

int strend(char*, char*);
int strlength(char*);

int main(){
   
   char s1[50];
   char s2[50];
   int end;

   printf("Enter first string: ");
   scanf("%s", s1);

   printf("Enter second string: ");
   scanf("%s", s2);
   
   end = strend(s1, s2);

   printf("%d\n", end);

   return 0;
}

int strlength(char s[]){
   
   int len = 0;
   int i;

   for(i = 0; s[i]; i++){
       len++;
   }

 return len;

}

int strend(char s1[], char s2[]){
   
   int i, j;
   int s1_len = strlength(s1);
   int s2_len = strlength(s2);

   i = s1_len - 1;
   j = s2_len - 1;

   while( s2[j] == s1[i]){
     
 	i--;
        j--;	
    
   }

   j++;

   if(j == 0){
       return 1;
   }else {
       return 0;
   }
}
