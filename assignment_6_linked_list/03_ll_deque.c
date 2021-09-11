/**
 * Program to implement deque functions using  linked list
 *
 * Compilation: gcc -o deque 03_ll_deque.c
 * Execution: ./deque
 *
 * @Muskan, 1910990681, 28/08/2021
 * Assignment 6 Linked List, Question 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

typedef struct Node{
   int value;
   struct Node* prev;
   struct Node* next;
} node;

// create a new node
node* createNode (int value){
    
    node *temp = (node*) malloc (sizeof(node));
    if(temp == NULL){
	return NULL;
    }

    temp -> value = value;
    temp -> prev = NULL;
    temp -> next = NULL;
    return temp;
}

// check if the deque is empty or not
int isEmpty(node *head, node *tail){
   
   if(head == NULL && tail == NULL){
       return 1;
   }

   return 0;
}

// adds value at head
void addHead(node **head, node **tail, int value){

   node *temp = createNode(value);

   if(temp == NULL){
       return;
   }

   if(isEmpty(*head, *tail)){
       (*head)= (*tail) = temp;
       return;
   }

   temp->next = (*head);
   (*head) -> prev = temp;
   (*head) = temp;
   
}

// adds value at tail
void addTail(node **head, node **tail, int value){
   
   node *temp = createNode(value);

   if(temp == NULL){
       return;
   }

   if(isEmpty(*head, *tail)){
       *head = temp;
       *tail = temp;
       return;
   }

   //if not empty, make temp last node
   
   temp -> prev = (*tail);
   (*tail) -> next = temp;
   (*tail) = temp;

}

// removes node from head, returns value at head
int removeHead(node **head, node **tail){

   if(isEmpty(*head, *tail)){
       return INT_MIN;
   }

   node *temp = *head;
   int value; 

   if((*head) -> next == NULL){

       value = temp -> value;
       (*head) = (*tail) = NULL;
       free(temp);
       return value; 
   }

   temp = *head;

   value = temp -> value;
   *head = temp -> next;
   temp -> next -> prev = NULL;
   free(temp);
   
   return value;
}

// remove node from tail, returns value at tail
int removeTail(node **head, node **tail){

   if(isEmpty(*head, *tail)){
       return INT_MIN;
   }

   int value;

   if((*head) -> next == NULL){
       node *temp = *head;
       value = temp -> value;
       *head = *tail = NULL;
       free(temp);
       return value;
   }

   node *temp = *head;

   value = temp -> value;
   *tail = (*tail) -> prev;
   (*tail) -> next = NULL;
   free(temp);

   return value;

}

// returns value at head
int peekHead(node *head, node *tail){
   if(isEmpty(head,tail)){
       return INT_MIN;
   }

   return head -> value;
} 

// returns value at tail
int peekTail(node *head, node *tail){
   if(isEmpty(head,tail)){
       return INT_MIN;
   }

   return tail -> value;
}

// check test cases
int main(){
   
   node *head = NULL;
   node *tail = NULL;

   assert(isEmpty(head,tail) == 1);
   addHead(&head, &tail, 10);
   assert(isEmpty(head,tail) == 0);
   addTail(&head, &tail, 7);
   addTail(&head, &tail, 19);
   assert(peekTail(head, tail) == 19);
   assert(removeTail(&head, &tail) == 19);
   addHead(&head, &tail, 12);
   assert(peekHead(head, tail) == 12);
   assert(removeHead(&head, &tail) == 12);
   assert(removeTail(&head, &tail) == 7);
   assert(removeHead(&head, &tail) == 10);
   assert(isEmpty(head, tail) == 1);

   return 0;
}
