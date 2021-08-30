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
#include <stlib.h>

struct Node{
   int value;
   struct Node* prev;
   struct Node* next;
}

struct Deque{
   struct Node *head;
   struct Node *tail;
}

typedef struct Node Node;
typedef struct Deque Deque;

Deque *createDeque(){
   Deque *deque == (Deque*)malloc(sizeof(Deque));
   deque->head = NULL;
   deque->tail = NULL;
}

Node *createNode(){
   Node *node = (Node*)malloc(sizeof(Node));
   node->prev = NULL;
   node->next = NULL;   
}

int is_empty(dq){
   
   if(dq->head == NULL|| dq->tail == NULL){
       return 1;
   }

   return 0;
}

void pushHead(Deque *dq, int value){

   Node *temp = createNode();
   temp = value;

   if(is_Empty(dq)){
       
       dq->head = temp;
       dq->head->prev = NULL;
       dq->head->next = NULL;

   }else{

       head->prev = temp;
       temp->next = head;
       head = temp; 
       head->prev = NULL;
   }
}

void pushTail(Deque *dq, int value){
   
   Node *temp = createNode();
   temp = value;

   if(is_empty(dq)){

       dq->head = temp;
       dq->tail = temp;

   }else{
    
       temp->prev = dq->tail;
       dq->tail->next = temp;
       dq->tail = temp;    

   }

}

int main(){
   
   Deque *dq = createDeque();
   
   printf("Pushed 10 at head");
   pushHead(dq, 10);

   printf("Pushed 4 at tail");
   pushTail(dq, 4);

   printf("Pushed 5 at tail");
   pushTail(dq, 5);

   printf("Pushed 7 at head");
   pushHead(dq, 7);

   printf("Peek head : %d\n", peekHead(dq));
   printf("Peek tail : %d\n", peekTail(dq));

   printf("Popped %d from head\n", popHead(dq);
   printf("Peek head : %d\n", peekHead(dq));

   printf("Popped %d from tail\n", popTail(dq);
   printf("Peek tail: %d\n", popTail(dq);

   return 0;
}
