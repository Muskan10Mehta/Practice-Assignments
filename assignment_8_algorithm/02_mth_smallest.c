/**
 * Program to find the mth smallest element from an unsorted array 
 * with runtime complexity <= O(n) with extra space requirement of O(1)
 *
 * Compilation: gcc -o mth_smallest 02_mth_smallest.c
 * Execution: ./mth_smallest.c
 *
 * @Muskan, 1910990681, 20/08/2021
 * Assignment 8 Algorithm, Question 2
 * Resources: sorting algorithm complexities, quick sort algorithm (geeksforgeeks)
 */

/** 
 * Quick sort has best case coplexity O(nlog n) for unsorted array
 * but the worst case complexity is O(n^2)
 *
 * as compared to merge sort which has the best case runtime complexity O(nlog n) 
 * same for worst case too
 *
 * but merge sort requires O(n) extra space, but quick sort doesn't
 * So let's try QUICK SORT
 * using pivot as last element always
 *
 */
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
  
   int temp;

   temp = *a;
   *a = *b;
   *b = temp;
    
}

int partition(int *array, int l, int r){
   
   int i, j;	
   int pivot;

   pivot = array[r];
   
   i = l - 1;

   for(j = l; j < r; j++){
       if(array[j]< pivot){
	  i++;
          swap(&array[i], &array[j]);
       }      
   }

   swap(&array[i + 1], &array[r]);

   return (i + 1);
}


void quickSort(int *array, int l, int r){
   
   int pivot;

   if(l < r){
       
       // the index of partition of array
       pivot = partition(array, l, r);
       
       // sort elements 
       quickSort(array, l, pivot - 1);
       quickSort(array, pivot + 1, r);    
   }

}

int main(){
   
   int i;
   int n;
   int m;

   printf("Enter the size of array: ");
   scanf("%d", &n);

   int array[n];

   printf("Enter the contents of array: ");

   for(i = 0; i < n; i++){
       scanf("%d", &array[i]);
   }

   printf("Enter the index for smallest element (m): ");
   scanf("%d", &m);

   quickSort(array, 0, n - 1);

   return 0;
}

