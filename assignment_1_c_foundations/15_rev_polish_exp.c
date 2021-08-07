/**
 * Program to compute the reverse polish expression
 *
 * Compilation: gcc -o rev_pol 15_rev_polish_exp.c
 * Execution: ./rev_pol
 *
 * @Muskan, 1910990681, 1/8/2021
 * Resources: thecrazyprogrammer (to read about reverse polish notation and to revise stacks)
 */

#include <stdio.h>


//global vriable to calculate top of stack
//initially it is -1 to indicate empty stack

int top = -1;


/** 
 * Function to check if the stack is full or not
 *
 * Parameters: 
 * size: size of stack
 *
 * returns: 1 if it is full, 0 if it isn't full
 */

int isFull(int size){

   if(top + 1 >= size){
   
	return 1;
   
   } else{
   
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

   } else{

        return 0;
   }

}

/**
 * Function to check if the character from string rev_polish is an operand i.e number or not
 *
 * Parameters:
 * char n: the character to check for operand
 *
 * returns: 1 if it is an operand, 0 if it isn't an operand
 */

int isOperand(char n){
 
   // comapring with range for ascii value 0(ascii -> 48) and 9(ascii -> 57)
   if( n >= 48 && n <= 57){
     
        return 1;

   } else {
   
	return 0;
   
   }

}

/**
 * Function to check if the character from string rev_polish is an operator or not
 *
 * Parameters:
 * char n: the character to check for operator
 *
 * returns: 1 if it is an operator, 0 if it isn't an operator
 */

int isOperator(char op){

   if(op == '+' || op == '-' || op == '/' || op == '*' || op  == '%' || op == '^'){

        return 1;

   } else {

        return 0;

   }

}


/**
 * Function to push the operand onto the stack
 *
 * Parameters:
 * int stack: the stack
 * int size: size of stack
 * int operand: value to push in stack
 *
 */

void push(int *stack, int size, int operand){

   if(!(isFull(size))){
        
	stack[++top] = operand;
   
   }   

}


/**
 * Function to pop the operand from the stack
 *
 * Parameters:
 * int stack: the stack
 * 
 * return: the popped element
 */

int pop(int *stack){

   int num = 0;

   if(!(isEmpty())){
   
	num = stack[top--];           
   }

   return num;

}


/**
 * Function to evaluate the expression when an operator is encountered in rev_polish string
 *
 * Parameters:
 * int n1: the first number
 * int n2: the second number
 * char op: operator 
 *
 * returns: computed result after operating the operands with operator
 */

int evaluate(int n1, int n2, char op){

   switch(op){
      
       case '+': return n1 + n2;
		 break;
       case '-': return n1 - n2;
		 break;
       case '/': return n1 / n2;
		 break;
       case '*': return n1 * n2;
		 break;
       case '%': return n1 % n2;
		 break;
       case '^': return n1 ^ n2;
		 break;
   }
}

/**
 * Function to calculate the reverse polish expressiom
 *
 * Parameters:
 * char rev_polish: the string containing reverse polish expressiom
 * int size: size of string
 *
 * returns: the result of the reverse polish expression
 */

int calculate_rev_polish_exp(char *rev_polish, int size){

   int stack[size];
   int n1;
   int n2;
   int res;
   
   int i = 0;
   int to_num = 0;


   // this loop checks each character from the reverse polish expression string
   // if the character is an operand it will push it onto the stack
   // if it is a operator it will pop the top two elements evaluate the result after operating them with the operator 
   // and push it back on the stack
   // this will go on until the expression is complete 
   // the final result will be saved on the first index of the stack and we will return that

   while( rev_polish[i]){
   
       if( isOperand(rev_polish[i]) ){
	   
	   // converting the string number to int
           to_num = rev_polish[i] - 48;

           push(stack, size, to_num);
	  
       
       } else if( isOperator(rev_polish[i]) ){     
	       n1 = pop(stack);
	       n2 = pop(stack);
               res = evaluate(n1, n2, rev_polish[i]);

	       // push result into stack
               push(stack, size, res);
	   }
       

       i++;
       }
   
   return stack[top];

}

int main(){
	
   int size; 
   int result = 0;
   char rev_polish[100];

   printf("Enter the size of Reverse Polish Expression: ");
   scanf("%d", &size);
   
   printf("Enter the Reverse Polish Expression: ");
   scanf("%s", rev_polish);
   
   result = calculate_rev_polish_exp(rev_polish, size);
   
   printf("Result = %d\n", result);

   return 0;
}
