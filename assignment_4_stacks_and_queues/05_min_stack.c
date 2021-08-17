/** 
 * Program to find minimum element from stack
 *
 * Coded on Leetcode: https://leetcode.com/submissions/detail/539821668/
 *
 * @Muskan, 1910990681, 09/08/2021
 * Assignment 4 Stacks and Queues, Question 
 */

typedef struct {

    int top;
    int size;
    int *array;

} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {

    MinStack* minStack = (MinStack*)malloc(sizeof(MinStack));
    minStack->size = 30000;
    minStack->top = -1;
    minStack->array = (int*)malloc(minStack->size * sizeof(int));

    return minStack;
}

void minStackPush(MinStack* obj, int val) {

    if(!(obj->top >= obj->size)){

        obj->top++;
        obj->array[obj->top] = val;

    }
}

void minStackPop(MinStack* obj) {
   int val;

   if(!(obj->top == -1)){

	val = obj->array[obj->top];
    obj->top--;
   }

   return val;
}

int minStackTop(MinStack* obj) {
  return obj->array[obj->top];
}

int minStackGetMin(MinStack* obj) {

    int i = 0;
    int min;
    min = obj->array[0];

    for(i = 0; i <= obj->top; i++){

         if(obj->array[i] < min){
             min = obj->array[i];
         }
    }
    return min;
}

void minStackFree(MinStack* obj) {
    obj->top = -1;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
