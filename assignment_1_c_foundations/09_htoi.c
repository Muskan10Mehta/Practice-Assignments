/**
 * Program to convert string of hexadecimal digits to its integer values.
 *
 * Complilation: gcc -o htoi 09_htoi.c
 * Execution: ./htoi
 *
 * @Muskan, 1910990681, 29 July 2021
 * Assignment 1 C Foundations (Question 9)
 * Resources: ASCII table, hex to decimal conversions
 */

#include <stdio.h>

int htoi(char*);
int strlength(char*);
int power(int, int);

int main(){
   
   char hex[20];
   int hex_to_int;

   printf("Enter the hexadecimal digits:");
   scanf("%[^\n]s", hex);
   
   hex_to_int = htoi(hex);
   
   printf("Integer value: %d\n", hex_to_int);

   return 0;

}

int strlength(char* hex){
   
   int len = 0;
   int i;
   
   // since last character on a character array is null 
   // the loop will stop when null character is encountered as it will be false

   for(i = 0; hex[i]; i++){
       len++;
   }

   return len;
}

int power(int base, int power){
   
   int res; // stores the result of base raised to power power
   int i = 0;
   
   res = base; //starting value 

   if(power == 0){
	
	return 1;

   } else if(power == 1){
	
	return base;

   } else {
   
	for(i = 0; i < power; i++){
	   res += res * base;
   	}

   return res;

   }
}

int htoi(char hex[]){

   int i;
   int p = 0; // power
   int base = 16;
   int int_val = 0; // stores int value of hex value
   int len = strlength(hex);
   
   for(i = len - 1; i >= 0; i--){
	
	if(hex[i] == 'x' || hex[i] == 'X'){
	   
	   break; // if the hex number has 0x or 0X in front it the loop will stop because thats extra

	}
       
	if(hex[i] >= 'a' && hex[i] <= 'f'){
         
	   int_val += (hex[i] - 97 + 10) * power(base, p); // -97 because value of a is 97

        }else if(hex[i] >= 'A' && hex[i] <= 'F'){
           
	   int_val += (hex[i] - 65 + 10) * power(base, p); // - 65 becasue value of A is 65

        }else{

           int_val += (hex[i] - 48)* power(base, p); // -48 becasue value of 0 is 48

        } 
        
	p++;
   } 

   return int_val;
}
