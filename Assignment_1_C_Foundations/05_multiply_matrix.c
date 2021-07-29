/**
 * Program to multiply two given matrices
 *
 * Complilation: gcc -o multiply 05_multiply_matrix.c
 * Execution: ./multiply
 *
 * @Muskan, 1910990681, 29 July 2021
 * Assignment 1 C Foundations Question 5
 */

#include <stdio.h>

int main(){
   
   int size;
   int i, j, k;

   printf("Enter the size of square matrix: ");
   scanf("%d", &size);

   int m1[size][size];
   int m2[size][size];
   int res[size][size];

   printf("Enter the content of matrix one: ");
   for(i = 0; i < size; i++){
       for(j = 0; j < size; j++){
           scanf("%d", &m1[i][j]);
       }
   }

   printf("Enter the content of matrix two: ");
   for(i = 0; i < size; i++){
       for(j = 0; j < size; j++){
           scanf("%d", &m2[i][j]);
       }
   }
   
   // calculates and stores multiplication result in res array

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
	    res[i][j] = 0;
  
	    for(k = 0; k < size; k++) {

                res[i][j] += m1[i][k] * m2[k][j];
	    }	    
	}
    }

   printf("Matrix 1 * Matrix 2 = \n");
   for(i = 0; i < size; i++){
       for(j = 0; j< size; j++){
           printf("%d ", res[i][j]);
       }
       printf("\n");
   }

   return 0;

}

