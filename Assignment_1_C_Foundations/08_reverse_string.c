/**
 * Program to build a fucntion to reverse an character array
 *
 * Compilation: gcc -o reverse_string 08_reverse_string.c
 * Execution: ./reverse_string
 *
 * @Muskan, 190990681, 28/07/2021
 * Assignment C Foundations, Question 8
 */

#include <stdio.h>

void reverse_string(char*);

int main(){
   
   char string[100];

   printf("Enter the string to be reversed: ");
   scanf("%[^\n]s", string);

   reverse_string(string);

   printf("%s\n", string);

   return 0;
}

/** Function to reverse the string by swapping array elements until it has reached the center of character array
  * 
  * Parameters: 
  * char array s
  */

void reverse_string (char* s){
   
   int i, j;
   int temp;
   int length; 
   for(i = 0; s[i];i++){
	length++;
   }

   i = 0;
   j = length - 1;

   while(j>i){
	  temp = s[i];
	  s[i] = s[j];
	  s[j] = temp;

	  i++;
	  j--;
      }

}
