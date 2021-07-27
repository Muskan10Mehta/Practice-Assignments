/**
 * C program to analyze the time taken by bubble sort algorithm for different array sizes
 *
 * Compilation: gcc -o bubble_sort bubble_sort.c
 * Execution: ./bubble_sort
 *
 * @Muskan, 1910990681, 27/07/2021
 * Day 2 Assignment
 * Resources: Stackoverflow (to understand how to get time elapsed)
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

/** Function for bubble sort
  * Parameters: 
  * array: point to integer array
  * n: size of the array
  */

void bubble_sort (int *array, int n)
{

  int i;
  int j;
  int flag = 0;
  
  for (i = 0; i < n - 1; i++){
      flag = 0;
      for (j = 0; j < n - i - 1; j++)
      {
      if (array[j] > array[j + 1]){
	      swap (array, j, j + 1);
	      flag = 1;
	    }
	}
      if (!flag){ //to check if the element has already been sorted
	    break;
	    }
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
  
  if (type == 'r' || type == 'R' || type == ' '{
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

  bubble_sort (array, size);
      
  gettimeofday (&t, NULL);
      
  long long endtime = t.tv_sec * 1000 + t.tv_usec / 1000;

  printf ("for size = %ld, time taken in miliseconds is = %lld\n", size, endtime - starttime); //prints time lapsed
    }

