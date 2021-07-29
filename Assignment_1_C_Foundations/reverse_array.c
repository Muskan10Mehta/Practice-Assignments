/**
 * Program to build a fucntion to reverse an array
 *
 * Compilation: gcc -o reverse_array reverse_array.c
 * Execution: ./reverse_array
 *
 * @Muskan, 190990681, 28/07/2021
 * Day 2 Assignment C Foundations
 */

#include <stdio.h>

void reverse_array(int*, int);

int main(){
   
   int size;
   int i;
   printf("Enter size of array: ");
   scanf("%d", &size);

   int array[size];
   printf("Enter the content of array: ");

   for(i = 0;i < size; i++){
	scanf("%d", &array[i]);
   }
   
   reverse_array(array, size);

   for(i = 0; i< size; i++){
	printf("%d ", array[i]);  
   }

   printf("\n");

   return 0;
}

void reverse_array(int array[], int size){
   
   int i = 0;
   int j = size - 1;
   int temp;

   while(j>i){
          temp = array[i];
	  array[i] = array[j];
	  array[j] = temp;
	  
   	i++;
   	j--;
   }
      }
   
