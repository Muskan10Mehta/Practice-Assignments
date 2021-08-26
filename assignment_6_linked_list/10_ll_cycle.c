/** 
 * Program to check if there exists a cycle in the linked list, if yes then return the node index where the cycle begins 
 
 * Coded on Leetcode
 *
 * @Muskan, 1910990681, 25/08/2021
 * Assignment 6 Linked List, Question 10
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    
    struct ListNode *slow_pointer = head;
    struct ListNode *fast_pointer = head;
    
    while(slow_pointer != NULL && fast_pointer != NULL){
        
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
        
        if(fast_pointer == slow_pointer){
             break;
        } 
    }
    
    if(slow_pointer != fast_pointer){
        return NULL;
    }
    
    fast = head;
    return slow_pointer;
}
