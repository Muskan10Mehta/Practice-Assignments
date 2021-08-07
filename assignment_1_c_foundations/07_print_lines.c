/**
 * Program to input a text file and print lines that are longer than 80 characters
 *
 * Complilation: gcc -o file 07_print_lines.c
 * Execution: ./file
 *
 * @Muskan, 1910990681, 31 July 2021
 * Assignment 1 C Foundations Question 7
 * Resources: w3resource.com (to revise file system in c), geeksforgeeks to read about fgets and fscanf
 */

#include <stdio.h>

int main(){
   
   int i = 0;
   char store_line[500];
   int length = 0;
   char c;

   // creates a pointer to the file 
   // opens the file  
   // r is for read-only

   FILE *f = fopen( "07_text.txt", "r" );

   // checks if file is empty or not
   if(f == NULL){
   
       printf("File not found");

   } else{
         
       // fgcanf reads from the given file
       // it takes a pointer to file, 
       // character input format, we can get the characters we want from the file
       // array or buffer to store the scanned characters in
       
       // here we are scanning lines until \n is encountered and storing them in store_line array until we reach enf of file	   
       while(fscanf(f, "%[^\n]%*c", store_line) != EOF){
           
	   length = 0;
           for(i = 0; store_line[i]; i++){
	       
	       length++;
	   
	   }
           
	   if(length > 80){
	   
		printf("%s", store_line);
	    
	   }
       
       }

   }

   fclose(f);
   
   return 0;
}	
