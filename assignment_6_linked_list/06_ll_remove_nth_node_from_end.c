/**
 * Program to remove nth node from end in a linked list
 *
 * Coded on leetcode
 *
 * @Muskan, 1910990681, 24/08/2021
 * Assignment 6 Linked List, Question 6
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    int len = 0;
    int i = 0;
    int n_front;

    struct ListNode* temp = head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    // get the length of the linked list
    while(temp){
        len++;
        temp = temp->next;
    }

    // if there is only one element in the linked list
    // return the list as it is

    if(n == len){

        return head->next;

    }else{
        
	// finding nth node from front
        n_front = len - n ;
        
	// run loop until the nth element is reached, which will be current element
	// and saving previous element to the current element
        for(i = 0; i < n_front; i++){
           prev = curr;
           curr = curr->next;
        }
        
	// assign the address of element after nth node to the node before nth element
        prev-> next = curr->next;

	// return linked list
        return head;
    }
}
