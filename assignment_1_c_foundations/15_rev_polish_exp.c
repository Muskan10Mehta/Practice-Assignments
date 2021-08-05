/**
 * Program to evaluate the reverse polish expression
 * 
 * Complilation: gcc -o rev_polish 15_rev_polish_exp.c
 * Execution: ./rev_polish
 *
 * @Muskan, 1910990681, 29 July 2021
 * Assignment 1 C Foundations, Question 15
 * Resources: thecrazyprogrammer (to understand reverse polish notation and to revise stack) 
 */


#include <stdio.h>

int isEmpty(int*);
int isFull(int*, int*, int);
int isOperand(char);
int isOperator(char);
void push(int*, int, int*, int);
int pop(int*, int*);
int evaluate(int, int, char);

int main(){
  
   int size;
   int i;
   int top = -1;
   int n, m, r;

   printf("Enter size of the input expression: ");
   scanf("%d", &size);

   int stack[size];
   char array[size];

   printf("Enter the reverse polish expression here: ");
   for(i = 0; i < size; i++){
      scanf("%c", array[i]);
   }
   
   for(i = 0; array[i]; i++){
       if(isOperand(array[i])){

	   push(stack, stack[i], top);

       }else if(isOperator(array[i])){
           n = pop(stack, &top);
	   m = pop(stack, &top);

	   r = evaluate(n, m, array[i]);
	   push(stack, r, &top);
       }       
   }
   printf("%d", stack[0]);
   return 0;
} 

int isEmpty(int *top){

   if(top == -1){
       return 1;
   }else{
       return 0;
   }

}

int isFull(int *stack; int *top, int size){

   if((top + 1) == size){
       return 1;
   }else{
       return 0;
   }

}

int isOperand(char i){

   if( i >= 48 && i <= 57){
       return 1;
   }else{
       return 0;
   }

}

int isOperator(char l){

   if( i == '+' || i == '-' || i == '/' || i == '%' || i == '^' || i == '*'){
       return 1;
   }else {
       return 0;
   }

}

void push(int *stack, char num, int *top, int size){
   
   if(isFull(stack, &top, size)){

        printf("stack is full");
	return; 

   }else{

        *top++;
	stack[*top] = num - 48;
   
   }

}

int pop(int *stack, int *top){
   
   char num;
   
   if(isEmpty(stack, &top)){

        printf("Stack is empty");
        return;

   }else{

        num = stack[*top] ;
        *top--;	
        return num;
   }


}

int evaluate(int n, int m, char op){
   
   if(op == '+'){
       return (n + m); 
   }else if(op == '-'){
       return (n - m);
   }else if(op == '/'){
       return (n / m);
   }else if(op == '%'){
       return (n % m);
   }else if(op == '^'){
       return (n ^ m);
   }else if(op == '*'){
       return (n * m);
   }
}
