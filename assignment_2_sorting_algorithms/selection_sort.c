/**
 * C program to analyze the time taken by selection sort algorithm for different array sizes
 *
 * Compilation: gcc -o selection_sort selection_sort.c
 * Execution: ./selection_sort
 *
 * @Muskan, 1910990681, 30/07/2021
 * Assignment 2 Sorting Algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/** Function swap two array elements
  * Parameters: 
  * array: point to integer array
  * j: index of element to be swapped with element at j + 1
  * k: index j + 1
  */

void swap (int *array, int j, int k)
{

  int temp = array[k];
  array[k] = array[j];
  array[j] = temp;

}

/** Function for selection sort
  * Parameters: 
  * array: point to integer array
  * n: size of the array
  */

void selection_sort (int *array, int n)
{

  int i;
  int j;
  int min_index = 0;
  
  for (i = 0; i < n - 1; i++){
      min_index = i;
      for (j = i + 1; j < n; j++)
      {
      if (array[j] < array[min_index]){
		min_index = j;
	    }
	}
      
      swap(array, min_index, i);
    }
}

int main (){
  
  long size;			// size of array
  char type;			// to get type of array
  int i;
  
  printf("Enter input size for array and array type seprated by space\nexample r for random, a for sorted, d for reverse sorted:");
  scanf("%ld", &size); //scans size of array
  scanf("%s", &type); // scans type of array

  int array[size];
  
  // if statements to check what type data array will have, 
  // r and black space for random,
  // a for ascending order sorted array
  // d for reversly sorted array
  
  if (type == 'r' || type == 'R' || type == ' '){
	  for (i = 0; i < size-1; i++)
	    {
	      array[i] = rand ();
	    }
	}

  if (type == 'a' || type == 'A'){
	  for (i = 0; i < size-1; i++)
	    {
	      array[i] = i;
	    }
	}

  if (type == 'd' || type == 'D'){
	  for (i = 0; i < size-1; i++)
	    {
	      array[i] = size-i;
	    }
	}
  
  // function to get time of day
  struct timeval t;

  gettimeofday (&t, NULL);

  long long starttime = t.tv_sec * 1000 + t.tv_usec / 1000; 

  selection_sort (array, size);
  
  gettimeofday (&t, NULL);
      
  long long endtime = t.tv_sec * 1000 + t.tv_usec / 1000;

  printf ("for size = %ld, time taken in miliseconds is = %lld\n", size, endtime - starttime); //prints time lapsed
}

