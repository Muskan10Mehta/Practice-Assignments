/**
 * Program contianing string library functions strncpy, strncat, strcmp which operated oon at most the firt n characters of their argument strings.
 * 
 * Complilation: gcc -o lib_fn  14_str_lib_functions.c
 * Execution: ./lib_fn
 *
 * @Muskan, 1910990681, 2/08/2021
 * Assignment 1 C Foundations Question 
 */

#include <stdio.h>

//void strncpy(char*, char*, int n);
//void strncat(char*, char*);
//void strn:cmp(char*, char*);
//void strnlen(char*);

int main(){

   char s[50];
   char t[50];

   printf("Enter first string: ");
   scanf("%[^\n]s",s);

   printf("Enter second string: ");
   scanf("%s",t);
   
   printf("%s",t);

   return 0;
}
