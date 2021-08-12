/**
 * Program to implement stack and stack functions in c
 *
 * Compilation: gcc -o stack stack.c
 * Execution: ./stack
 *
 * @Muskan, 1910990681, 06/08/2021
 */

#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

// Checks if stack if full or not
int isFull(){

   if(top + 1 >= SIZE){

	return 1;

   } else {

        return 0;
   }

}

// Checks if stack is empty or not
int isEmpty(){

   if(top == -1){

        return 1;

   } else {

        return 0;
   }

}
 
// Adds a new element to the stack
void push(int value){
   
    if(!(isFull())){
     
	  stack[++top] = value;  
     
    }

}

// Remove and return the element from the stack.
int pop(){
     
    int element = 0;

    if(!(isEmpty())){
       
       element = stack[top];
       stack[top] = -1;
       top--;
          
    }
    return element;
}

// Return but not remove the element at the top of the stack.
int peek(){

   return stack[top];

}

int main(){

   int i = 0;

   // Adding numbers 1-5 in stack

   while(i < 5){
   
       push(i + 1);
       printf("Pushed %d to stack\n", i + 1);
       i++;

   }

   printf("Top element of stack = %d\n", peek());
   printf("Pop element from stack = %d\n", pop());
   printf("Pop element from stack = %d\n", pop());
   printf("Pushing a new element to stack, say 6\n");
   push(6);
   printf("Top element of stack = %d\n", peek());

   return 0;

}
