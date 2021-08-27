/**
 * Program to implement Queue with linked list
 *
 * Compilation: gcc -o queue 02_ll_queue.c
 * Execution: ./queue
 *
 * @Muskan, 1910990681, 24/08/2021
 * Assignment 6 Linked List, Question 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
  int value;
  struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void push (int val)
{
   struct Node* new_value = (struct Node*) malloc (sizeof(struct Node));
   new_value->value = val;
   new_value->next = NULL;
   
   if((head == NULL) && (tail == NULL))
   {
       head = tail = new_value;
   }else
   {
       tail->next = new_value;
       tail = new_value;
   }
}

int pop()
{
     struct Node* temp;
    
    temp = head;
    
    if(temp == NULL)
    {
       printf("Queue Empty\n");
        
    }else
    {
        if(temp->next != NULL)
        {
            temp = temp->next;
            printf("POP: %d\n", head->value);
            free(head);
            head = temp;
            
        }else
        {
            printf("POP: %d\n", head->value);
            free(head);
            head = NULL;
            tail = NULL;
            
        }
    }
     
}

int peek()
{
 if((head == NULL) && (tail == NULL))
     {
         return INT_MIN;
     }
     
         return head->value;

}

int is_empty()
{
    if(head == NULL && tail == NULL) return 1;
    return 0;
}

int main ()
{
  push(18);
  push(11);
  pop();
  printf("EMPTY: %d\n", is_empty());
  pop();
  printf("what");
  printf("EMPTY: %d", is_empty());
  push(10);
  printf("PEEK: %d\n", peek());
  push(10);
  pop();
  
  return 0;
}
