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

int strnlen(char* line)
{
    int i = 0;
    int length = 0;

    while(line[i]){
        length++;
	i++;
    }

    return length;
}

int main()
{
   
   char temp_line[200];
   FILE* fp;

   // open a file in read mode

   fp = fopen("07_text.txt", "r");

   // check if file is empty or not

   if(fp == NULL)
   {
       printf("File is empty.");
       return 0;
   }
   
   // else get lines from files and check if they are greater than 80 characters
   // fgets get a line from the file pointer provided

   while(fgets(temp_line, 200, fp))
   {
	if(strnlen(temp_line) > 80)
	{
	    printf("%s", temp_line);
	}
   }

   // close file after we have reached the EOF
   fclose(fp);

   return 0;
}	
