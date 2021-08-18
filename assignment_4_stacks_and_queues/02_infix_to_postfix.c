/** Program to convert infix to postfix
 *
 * Compilation: gcc -o postfix 02_infix_to_postfix.c
 * Execution: ./postfix
 *
 * @Muskan, 1910990681, 10/08/2021
 * Assignment 4 Stacks and Queues, Question 2
 */

#include <stdio.h>

#define SIZE 100

char stack[SIZE];
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
void push(char value){

    if(!(isFull())){
          stack[++top] = value;
    }
}

// Remove and return the element from the stack.
char pop(){
 char element = 0;

    if(!(isEmpty())){

       element = stack[top];
       stack[top] = -1;
       top--;

    }

    return element;
}

// Returns the element at the top of stack
int peek(){

   return stack[top];

}

int precedence_order(char op){

  if(op == '*' || op == '/' || op == '%'){
       return 3;
  }else if(op == '+' || op == '-'){
       return 2;
  }else{
       return 1;
  }

  return 0;
}

void infix_to_postfix(char *infix){

   int i = 0;
   char temp;
   char in;

   for(i = 0; infix[i]; i++){
     
       if(infix[i] >= 48 && infix[i] <= 57){
           printf("%c", infix[i]);
       } else if(infix[i] == '('){
           push(infix[i]);
       } else if(infix[i] == ')'){
	   temp = pop();
	   if(temp != '('){
           while(peek() != '(' && !(isEmpty())){
               printf("%c\n", temp);
	   }
           }
       } else {
           
           while(precedence_order(infix[i]) <= precedence_order(peek()) && !(isEmpty())){
                printf("%c", pop());
           }
           
          push(infix[i]);
       }
   }
   
   while(!(isEmpty())){
       temp = pop();
       if(temp != '('){
       printf("%c\n ", temp);
       }
   }
}

int main(){

   char infix[100];
   printf("Enter the infix expression: ");
   scanf("%[^\n]s", infix);

   infix_to_postfix(infix);

   return 0;

}

