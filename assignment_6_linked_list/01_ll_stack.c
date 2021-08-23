/**
 * Program to implement stack using linked list
 *
 * Compilation: gcc -o stack stack.c
 * Execution: ./stack
 *
 * @Muskan, 1910990681, 23/08/2021
 * Assignment 6 Linked List, Question 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node{
   
   int value;
   struct Node* next;

};

struct Node* top = NULL;

void push(int value){
   
   struct Node* temp = (struct Node*)malloc( sizeof(struct Node));

   if(temp == NULL){
       return;
   }    

   temp->value = value;
   temp->next =  top;
   
   if(top == NULL){
        top = temp;
   }else{
	
	temp->next = top;
        top = temp;
   }

}

int pop(){
    
    if(top == NULL){
       return INT_MIN;
    }
    
    struct Node* temp = top;

    top->value = temp->value;
    top = temp;

    return top->value;
}

bool is_empty(){
   if(top == NULL){
        return true;
   }else {
        return false;
   }
}

int peek(){
   if (is_empty()){
       return INT_MIN;
   }else{
       return top->value;
   }
}

int main(){

   printf("Pushed 9\n");
   push(9);
   printf("Is Empty %zu\n", sizeof(is_empty()));
   printf("Pop %d\n", pop());
   printf("Is Empty %d\n", is_empty());
   printf("Pushed 10\n");
   push(10);
   printf("Peek %d\n", peek());
   return 0;
}
