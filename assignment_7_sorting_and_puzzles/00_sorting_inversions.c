/**
 * Program to count inversions for sorting an array, for sorted array inversions are zero, for reverse sorted array inversion couunt is maximum
 *
 * Compilation: gcc -o inversion 00_sorting_inversion_count.c
 * Execution: ./inversion
 *
 * @Muskan, 1910990681, 11/08/2021
 * Assignment 7 Sorting and Puzzles, Question 1 for Sorting
 */


#include <stdio.h>

/** Function swap two array elements
  * Parameters:
  * array: point to integer array
  * j: index of element to be swapped with element at j + 1
  * k: index j + 1
  */

void swap (int *array, int j, int k){

  int temp = array[k];
  array[k] = array[j];
  array[j] = temp;

}

/** Function for bubble sort
  * Parameters:
  * array: point to integer array
  * n: size of the array
  */

int bubble_sort (int *array, int n)
{

   int i;
   int j;
   int inversion = 0;
   int flag = 0;

   for (i = 0; i < n - 1; i++){
      
      flag = 0;

      for (j = 0; j < n - i - 1; j++){
           
	   if (array[j] > array[j + 1]){
	            
	       swap (array, j, j + 1);
	       inversion++;
	      
	       flag = 1;

	   }
      }

      if (!flag){ //to check if the element has already been sorted
	    break;
      }  
   }

   return inversion;
}

int main (){

   int size;
   int i;
   int inversion_count = 0;

   printf("Enter input size for array: ");
   scanf("%d", &size); //scans size of array


   int array[size];
   
   printf("Enter the array elements: ");
   for(i = 0; i < size; i++){
   
	scanf("%d", &array[i]);
   
   }
  
   inversion_count = bubble_sort (array, size);

   printf("Inversion count = %d\n", inversion_count);

   return 0;  
}
