/** 
 * Program to delete duplicate elements from a linked list and return a sorted linked list
 *
 * Coded on Leetcode
 *
 * @Muskan, 1910990681, 26/08/2021
 * Assignment 6 Linked List, Question 5
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){


    struct ListNode *prev = head;
    struct ListNode *curr = prev;

    while(prev){

        if(prev->next != NULL && prev->val == prev->next->val){
            while(prev->next != NULL && prev->val == prev->next->val){
                prev = prev->next;
            }
            curr = prev->next;
        } else{
            curr = curr->next;
        }

        prev = prev->next;
    }
    return head;
}


