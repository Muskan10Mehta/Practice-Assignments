/**`:`
 * Program contianing string library functions strncpy, strncat, strcmp which operated oon at most the firt n characters of their argument strings.
 * 
 * Complilation: gcc -o lib_fn  14_str_lib_functions.c
 * Execution: ./lib_fn
 *
 * @Muskan, 1910990681, 2/08/2021
 * Assignment 1 C Foundations Question 
 */

#include <stdio.h>

int slen(char *s){
   
   int len = 0;
   int i;

   for(i = 0; s[i]; i++){
       len++;
   }

   return len;
}

void cpy(char *s, char *t, int n){

   int i = 0;
   if(slen(t) < n || slen(s) < n){
      printf("String length is less than n, cannot copy\n");
      return;
   }

   for(i = 0; i < n ; i++){
      s[i] = t[i];
   }

}

void cat(char *s, char *t){

   int i, j;
   i = slen(s);
   j = slen(t);
    
   if( i + j >= 50){
      printf("String length of string one is not enough\n");
      return;
   }

   
   for(j = 0; t[j]; j++,i++)
   {
	s[i] = t[j];
   }
  
}

int cmp(char *s, char *t){

   int i;
   int flag = 0;

   if(slen(s) == slen(t)){

   for(i = 0; i < slen(s); i++){

        if(s[i] == t[i]){
           flag = 1;
        } else{
           flag = 0;
           break;
        }

   }

   if(flag == 1){
        return 1;
   }else {   
	return 0;}

}
}


int main(){

   char s[50];
   char t[50];
   int n;
   int flag = 0;
   int function;

   printf("Enter first string: ");
   scanf("%s",s);

   printf("Enter second string: ");
   scanf("%s",t);
   
   printf("Enter the number for function you want to perform on strings\n 1 for strcat\n 2 for strcat\n 3 for strcmp\n");
   scanf("%d", &function);

   if(function == 1){
   
	printf("For copying n character of string two to string one to enter value of n: ");
	scanf("%d", &n);
	cpy(s, t, n);
	printf("\nCopied %d characters of string two to string one: %s\n", n, s);

   } else if(function == 2){
   
	cat(s, t);
	printf("Concatenated string two to string one: %s\n", s);

   } else if(function == 3){
   	flag = cmp(s, t);
  
   	if( flag == 1){
   	printf("Strings are equal\n");
   	} else {
   	printf("Strings are not equal\n");

   }
   }
   return 0;
}
