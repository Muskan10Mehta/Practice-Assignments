/** 
 * Program to find largest rectangle's area from the given histogram
 *
 * Compilation: gcc -o histogram 04_largest_histogram.c
 * Execution: ./histogram
 *
 * @Muskan, 190990681, 10/08/2021
 * Assignment 4 Stacks and Queues, Question 4
 */


#include <stdio.h>

int queue[100];
int head = -1;
int tail = -1;


void push(int value){
    
    if(!(tail >= 100)){
       
        if(head == -1){
            
            head = 0;
            
        }
        
        queue[++tail] = value;
        
    }
    
}

int pop(){
    
    int value = 0;
    int i = 0;
    if(!(head == -1)){
       
       value = queue[head];
       while(i < tail){
       
           queue[i] = queue[i + 1];
	    i++;
       }   

       tail--;
          
    }
    return value;
    }
    


int largestRectangleArea(int* heights, int heightsSize){
    int max_from_queue = 0;
    int max = 0;
    int i = 0;
    int j = 0;
    int bars = 0;
    int temp_res = 0;
    
    while(i < heightsSize){
        
        max  = heights[i];
        push(max);
        bars++;
        
        while(heights[i + 1] >= max && (i + 1) <= heightsSize){
            
            max = heights[i + 1];
            push(heights[i + 1]);
            bars++;
            i++;
        } 
        
        while(bars){
            
            temp_res = (pop())* bars;
            if(max_from_queue < temp_res){
                    max_from_queue = temp_res; 
            }           
            --bars;        
        }
        i++;
    }
    return max_from_queue;
}

int main() {

   int i;
   int size ;

   printf("Enter the size of input: ");
   scanf("%d", &size);

   int heights[size];

   printf("Enter the heights of bars in histogram: ");
   for(i = 0; i < size; i++){
       scanf("%d", &heights[i]);
   }

   int res = largestRectangleArea(heights, size);
   
   printf("%d\n", res);
    
   return 0;
}
