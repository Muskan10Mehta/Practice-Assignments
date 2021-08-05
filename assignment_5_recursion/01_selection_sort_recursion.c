/**
 * Implementing selection sort with recursion
 *
 * Compilation: gcc -o selection_sort selection_sort_recursion.c
 * Execution: ./selection_sort
 *
 * @Muskan, 1910990681, 4/08/2021
 * Assignment 5 Recursion Question 1
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/** Function swap two array elements
  *
  * Parameters: 
  * array: point to integer array
  * j: index of element to be swapped with element at i
  * k: index of minimum element
  */

void swap (int *array, int j, int k)
{

  int temp = array[k];
  array[k] = array[j];
  array[j] = temp;

}

/** Recursive function for selection sort
  * 
  * Parameters: 
  * array: point to integer array
  * n: size of the array
  * i: starting index 0
  * j: index i + 1
  * min: minimum element
  */

void selection_sort (int *array, int n, int i, int j, int flag){
   

   if(i < n - 1 ){
        
       if(flag == 1){	
	
	   j = i + 1;

       }

	   if(j < n){
	       if( array[j] < array[i]){
	       
		   swap(array, j, i);
	    
	        }
	    
                 selection_sort(array, n, i, j + 1, 0);
	}
	
        selection_sort(array, n, i + 1, 0, 1);
   
   }

}

int main (){
  
  long size;			// size of array
  int i;
  
  printf("Enter input size: ");
  scanf("%ld", &size); //scans size of array

  int array[size];
  
  for (i = 0; i < size; i++){
	 
       array[i] = rand ();
	
   } 

   selection_sort (array, size, 0, 0, 1);

   printf("Sorted array: ");

   for (i = 0; i < size; i++){
        
       printf("%d ", array[i]);
        
   }

   printf("\n");

   return 0;
}

