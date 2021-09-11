/**
 * Program to Reverse a sublist in a linked list
 *
 * Coded on Leetcode
 *
 * @Muskan, 1910990681, 26/08/2021
 * Assignment 6 Linked List Question 7
 * Resources: Classroom Discussion
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    
    if(left == right){
        return head;
    }
    
    ListNode *before = NULL;
    ListNode *curr = head;
    ListNode *front = NULL;
    ListNode *prev = NULL;
    
    int i = 1;
    
    while(i <= right){
        
        if(i < left){
            before = curr;
            curr = curr -> next;
        } else {
            if(i == left){
                front = curr;
            }
            
            ListNode * after = curr-> next;
            curr -> next = prev;
            prev = curr;
            curr = after;
        }
        i++;
    }
    
    // curr is node after right
    // prev is node at right
    // front is the node at left
    // before is the node before left
    
    if(left == 1){
        head = prev;
    } else{
        before -> next = prev;
    }
    
    front-> next = curr;
    
    return head;
}
