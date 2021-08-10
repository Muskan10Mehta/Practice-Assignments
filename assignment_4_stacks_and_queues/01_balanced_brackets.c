/** 
 * Program to check if the given string of brackets is balanced or not
 *
 * Compilation: gcc -o balanced_brackets 01_balanced_brackets.c
 * Execution: ./balanced_brackets
 *
 * @Muskan, 1910990681, 10/08/2021
 * Assignment 4 Stacks and Queues, Question 1
 * Resources: stackoverflow (how to print boolean)
 */

#include <stdio.h>
#define SIZE 100

char stack[SIZE];
int top = -1;


/**
 * Function to check if the stack is full or not
 *
 * returns: 1 if it is full, 0 if it isn't full
 */

int isFull(int size){

   if(top + 1 >= size){

	return 1;

   } else {

        return 0;
   }

}

/**
 * Function to check if the stack is empty or not
 *
 * returns: 1 if it is empty, 0 if it isn't empty
 */

int isEmpty(){

   if(top == -1){

        return 1;

   } else {

        return 0;
   }

}

/**
 * Function to push the operand onto the stack
 *
 * Parameters:
 * char value: value to push in stack
 *
 */

void push(char value){

   if(!(isFull(SIZE))){

	stack[++top] = value;

   }

}


/**
 * Function to pop the operand from the stack
 *
 * return: the popped element
 */

int pop(){

   char bracket;

   if(!(isEmpty())){

	bracket = stack[top--];
   }

   return bracket;

}

int balanced_brackets(char *exp){

   int i = 0;
   char br;
   int flag = 0;

   for(i = 0; exp[i]; i++){

	if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
	   
	   push(exp[i]);
	
	} else if(exp[i] == ')'){
	
	   br = pop();

	   if( br == '('){
	   
	       flag = 1;
	       
	   } else {
	   
               flag = 0;
	       break;

	   }
 
	} else if(exp[i] == '}'){

           br = pop();

           if( br == '{'){

               flag = 1;

           } else {

               flag = 0;
               break;

           }

        }  else if(exp[i] == ']'){

           br = pop();

           if( br == '['){

               flag = 1;

           } else {

               flag = 0;
               break;

           }

        }


   }

   if(flag == 1){
       return 1;
   } else{
       return 0;
   }

}

int main(){
   
   char exp[100];
   
   printf("Enter string: ");
   scanf("%s", exp);

   printf("%s\n", balanced_brackets(exp)? "true": "false");
   
   return 0;
}

