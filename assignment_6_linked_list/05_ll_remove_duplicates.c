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
     
  if (head == NULL || head->next == NULL) {
        return head;
    }
    
    int duplicate_value;
    
    struct ListNode *temp = (struct ListNode *) malloc(sizeof(struct ListNode));
    temp->val = head->val;
    temp->next = head;
    
    struct ListNode *curr = temp;
    
    while (curr->next != NULL && curr->next->next != NULL) {
        
        // check duplicate 
        if (curr->next->val == curr->next->next->val) {
            
            duplicate_value = curr->next->val;
            // remove duplicates 
            while (curr->next != NULL && curr->next->val == duplicate_value) {
                struct ListNode *duplicate = curr->next;
                curr->next = curr->next->next;
                free(duplicate);
            }
        } else {
            curr = curr->next;
        }
    }
    return temp->next;
}



