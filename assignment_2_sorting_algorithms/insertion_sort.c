/**
 * C program to analyze the time taken by insertion sort algorithm for different array sizes
 *
 * Compilation: gcc -o insertion_sort insertion_sort.c
 * Execution: ./insertion_sort
 *
 * @Muskan, 1910990681, 31/07/2021
 * Assignment 2 Sorting Algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/** Function for selection sort
  * Parameters: 
  * array: point to integer array
  * n: size of the array
  */

void selection_sort (int *array, int n)
{

  int i;
  int j;
  int key;
  
  for (i = 1 ; i < n ; i++){
      key = array[i];
      j = i - 1;

      while (j >= 0 && array[j] > key){
           array[j + 1] = array[j];
	   j = j - 1;
      }
      
        array[j + 1] = key;
    }
}

int main (){
  
  long size;			// size of array
  char type;			// to get type of array
  int i;
  


  printf("Enter input size for array and array type seprated by space\nexample r for random, a for sorted, d for reverse sorted: ");
  scanf("%ld", &size); //scans size of array
  scanf("%s", &type); // scans type of array

  int array[size];
  
  // if statements to check what type data array will have, 
  // r and black space for random,
  // a for ascending order sorted array
  // d for reversly sorted array
  
  if (type == 'r' || type == 'R' || type == ' '){
	  for (i = 0; i < size; i++)
	    {
	      array[i] = rand ();
	    }
	} else if (type == 'a' || type == 'A'){
	  for (i = 0; i < size; i++)
	    {
	      array[i] = i;
	    }
	} else if (type == 'd' || type == 'D'){
	  for (i = 0; i < size; i++)
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

