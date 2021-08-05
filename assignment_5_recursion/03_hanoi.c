/**
 * Program to implement tower of hanoi 
 *
 * Complilation: gcc -o hanoi hanoi.c
 * Execution: ./hanoi
 *
 * @Muskan, 1910990681, 5/8/2021
 * Assignment 1 C Foundations Question 3 
 * Resources: geeksforgeeks (to read about tower of hanoi)
 */

#include <stdio.h>

int mv = 0; //global variable to count movements

/**
 * Recursive Function to print movements for tower of hanoi
 *
 * Parameters: 
 * n : integer number of disks
 * from : character for 'from' rod, from which the disk would move to 'to' rod
 * to : character for 'to' rod
 * aux : auxiliary rod, the third helping rod
 *
 */

void tower_of_hanoi (int n, char from, char to, char aux){
    
    // base case 	
    if(n == 1){
       
       printf("%c to %c\n", from, to); 
       mv++;
       return;
    
    }
    
   // moves all disks except the last disck to aux rod

   tower_of_hanoi(n - 1, from, aux, to);

   printf("%c to %c\n", from, to);
   mv++;

   // moves the disks from aux to 'to' rod

   tower_of_hanoi(n - 1, aux, to, from);
}

int main(){
   
   int n;

   printf("Enter the number of disks: ");
   scanf("%d", &n);

   tower_of_hanoi(n, 'A', 'C', 'B');

   printf("Total movements required = %d\n", mv);

   return 0;
}
