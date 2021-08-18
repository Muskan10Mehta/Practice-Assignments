/** 
 * Program to implement stack from queues
 *
 * Coded on leetcode 
 *
 * @Muskan, 1910990681, 16/08/2021
 * Assignment 4 Stacks and Queues, Question 3 
 */

// strcut for queue
typedef struct {
    
    int head;
    int tail;
    int *array;
    int top; 
    
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    
    MyStack *queue = (MyStack *) malloc (sizeof(MyStack));
    queue->head = 0;
    queue->tail = 0;
    //in a stack from queue, the top would be the tail where the latest element was added
    queue->top = queue->tail;
    queue->array = (int *) malloc(1000 * sizeof(int));
    
    return queue;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    
  //if the stack is not empty	
  if(!(obj->tail >= 1000)){
      
      //add element at tail
      obj->tail = obj->tail + 1;
      obj->array[obj->tail] = x;
     
  }
}


/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
  return (obj->head == obj->tail || obj->tail == 0);
}

/** Removes the element from the queue and returns that element. */
int pop(MyStack* obj){
    
    int i = 0;
    int val = 0;
    val = obj->array[obj->head];
    
    deletes
    for(i = 0; i <= obj-> tail; i++){
            obj->array[i] = obj->array[i + 1];   
    }

    obj->tail--;
    
    return val; 
}

/** Removes the element at the top of stack and returns that element. */
int myStackPop(MyStack* obj) {
    
    int i = 0;
    int val = 0;
    
    // pops element if the stack is non empty
    if(!(myStackEmpty(obj))){
       
       // setting top as tail of queue, as the element at tail is latest
       obj->top = obj->tail - 1;
        
       // reverses the queue so the tail becomes head
       while(obj->top >= obj->head){
	   // pops element from queue and adds it back at the tail of queue
	   // by doing this wwe are moving the top towards head
           myStackPush(obj, pop(obj));
           obj->top--;
       }
       
       // now that the element at tail has reached head, it becomes top of stack and we return it
       val = pop(obj);
    }
    
    return val;
}


/** Get the top element. */
int myStackTop(MyStack* obj) {
    
  return obj->array[obj->tail];
}


void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
