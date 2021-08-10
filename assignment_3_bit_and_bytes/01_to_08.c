/**
 * Program to create functions for different bitwise operators.
 * 1. BitAnd
 * 2. BitXor
 * 3. CheckSign
 * 4. GetByte
 * 5. LogicalShift
 * 6. Conditional
 * 7. Bang
 * 8. Invert
 *
 * Compilation: gcc -o bit 01_to_08.c
 * Execution: ./bit
 *
 * @Muskan, 19010990681, 09/08/2021
 * Assignment 4 Bits and Bytes
 *
 * Resources: stackoverflow ( to read about ~ operator )
 */

#include <stdio.h>

int bitAnd(int x, int y){

   int and = 0;

   and = ~(~(x)| ~(y));

   printf("Bit AND on %d and %d is %d\n", x, y, and);

   return 0;
}

int bitXor(int x, int y){

   int xc;
   int yc;
   int xor;

   // using AB' + B'A

   xc = ~(x);
   yc = ~(y);
   xor = (x & yc) + (y & xc);
   
   printf("%d XOR %d is %d\n", x, y, xor);

   return 0;

}

int sign(int x){
   
   // getting 2's complement of number
   // complementaing the number using ~ operator
   // and adding one
   
   x = ~(x) + 1;

   // getting the most significant bit 
   // as that indicates the sign in 2's compliment of a number 
   // & the number with 1000
   // 1 indicates negative
   // 0 indicates positive
   // since 1 & 1 is 1 if the msb is 1 x will be 1000
   // 1 & 0 is 0 then msb is 0 x will be 0000

   x = x & 1000;

   // comparing with 8 as binary for 8 is 1000
 
   printf("Sign is: ");

   if(x == 8){
       printf("1\n");
   }else{
       printf("-1\n");
   }

} 

int getByte(int x, int n){
   
   
   return 0;
}

int logicalShift(int x, int n){


    
   return 0;
}

int conditional(int x, int y, int z){

  

  return 0;
}

int bang(int x){

  
  return 0;
}

int invert(int x){

   return 0;
}

int main(){

   int x, y, z, n;
   int fn;

   printf("Enter the number for the fucntion you want to use:\n1 bitAnd\n2 bitXor\n3 sign\n4 getByte\n5 logicalShift\n6 conditional\n7 bang\n8 invert\n ");

   scanf("%d", &fn);

   if(fn == 1){
       
       printf("Enter first number: ");
       scanf("%d", &x);

       printf("Enter second number: ");
       scanf("%d", &y);

       bitAnd(x, y);

   } else if(fn == 2){
        
	   printf("Enter first number: ");
           scanf("%d", &x);

           printf("Enter second number: ");
           scanf("%d", &y);

	   bitXor(x,y);

   } else if (fn == 3){

	   printf("Enter the number: ");
           scanf("%d", &x);

	   sign(x);

   } else if (fn == 4){

           printf("Enter the number: ");
           scanf("%d", &x);
           
	   printf("Enter the byte to extract: ");
           scanf("%d", &n);

           getByte(x, n);

   }  else if (fn == 5){

           printf("Enter the number: ");
           scanf("%d", &x);

           printf("Enter n for shift: ");
           scanf("%d", &n);

           logicalShift(x, n);


   }  else if (fn == 6){

           printf("Enter value for x: ");
           scanf("%d", &x);
           
	   printf("Enter value for y: ");
           scanf("%d", &y);
          
	   printf("Enter value for z: ");
           scanf("%d", &z);

           conditional(x, y, z);

   }  else if (fn == 7){

           printf("Enter the number: ");
           scanf("%d", &x);

           bang(x);

   }  else if (fn == 8){

           printf("Enter the number: ");
           scanf("%d", &x);

           invert(x);

   }

   return 0;
}

