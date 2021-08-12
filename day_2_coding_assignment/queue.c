/**
 * Program to implement queue in c
 *
 * Compilation: gcc -o queue queue.c
 * Execution: ./queue
 *
 * @Muskan, 1910990681, 10/08/2021
 */

#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int head = -1;
int tail = -1;

// Checks if queue if full or not
int isFull(){

   if(tail + 1 >= SIZE){

	return 1;

   } else {

        return 0;
   }

}

// Checks if queue is empty or not
int isEmpty(){

   if(head == tail){

        return 1;

   } else {

        return 0;
   }

}
 
// Adds a new element to the queue
void push(int value){
   
    if(head == -1){
    
	head = 0;
    
    } 
    
    if(!(isFull())){
     
	 queue[++tail] = value;  
     
    }
    
}

// Remove and return the element from the queue
int pop(){
     
    int element = 0;
    int i = 0;

    if(!(isEmpty())){
       
       element = queue[head];
       
       while(i < tail){
       
           queue[i] = queue[i + 1];
	   i++;
       }   

       tail--;
          
    }
    return element;
}

// Return but not remove the element at the top of the queue
int peek(){

   return queue[head];

}

int main(){

   int i = 0;

   // Adding numbers 1-5 in stack

   while(i < 5){
   
       push(i + 1);
       printf("Pushed %d to queue\n", i + 1);
       i++;

   }

   printf("Head element of queue = %d\n", peek());
   printf("Pop element from queue = %d\n", pop());
   printf("Pop element from queue = %d\n", pop());
   printf("Pushing a new element to queue, say 6\n");
   push(6);
   printf("Head element of stack = %d\n", peek());
   printf("Head = %d, Tail = %d\n", head, tail);
   return 0;

}
