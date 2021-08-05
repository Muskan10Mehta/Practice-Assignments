/**
 * Program that returns the rightmost index in string 1 where string 2 occurs
 * returns -1 if there is none
 *
 * Complilation: gcc -o any 11_any_match.c
 * Execution: ./any
 *
 * @Muskan, 1910990681, 29 July 2021
 * Assignment 1 C Foundations Question 12 
 */

#include <stdio.h>

int strindex(char*, char*);
int strlength(char*);

int main(){
   
   char s1[50];
   char s2[50];
   int index;

   printf("Enter first string: ");
   scanf("%s", s1);

   printf("Enter second string: ");
   scanf("%s", s2);
   
   index = strindex(s1, s2);

   printf("%d\n", index);

   return 0;
}
int strlength(char s[]){
    int i;
    int len = 0;

    for(i = 0; s[0]; i++){
       len++;
    }

    return len;
}

int strindex(char s1[], char s2[]){
   
   int index = 0;
   int flag = 0;
   int i, j;
   
   int s1_len = strlength(s1);
   int s2_len = strlength(s2);

   i = s1_len - 1;
   j = s2_len - 1;
   

   // matching from the end
   // from the end the first index we find will be the rightmost index

   while(i >= 0){
        j = s2_len - 1;
	while(s2[j] == s1[i]){
		i--;
		j--;
	}

	if(j == 0){
	   flag = 1;
	   index = i;
	   break;
	}

	i--;
   }


   if(flag == 1){
      return index;
   }else {
       return -1;}
}
