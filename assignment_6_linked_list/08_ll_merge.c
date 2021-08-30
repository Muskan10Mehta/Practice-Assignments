/**
 * Program to merge two sorted linked list
 *
 * Coded on leetcode
 *
 * @Muskan, 1910990681, 30/08/2021
 * Assignment 6 Linked List, Question 8
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* res = (struct ListNode* )malloc(sizeof(struct ListNode));

    if(l1 == NULL && l2 == NULL){
        return l1;
    }else{
        if(l1 == NULL && l2!= NULL){
            return l2;
        }else if(l1 != NULL && l2 == NULL){
            return l1;
        }

    }

    while(l1 != NULL && l2 != NULL){

         if(l1->val <= l2->val){
             res->val = l1->val;
             res->next = l1->next;
             printf("in if%d\n ", res->val);
             l1 = l1->next;

         }else{
             res->val = l2->val;
                res->next = l2->next;
              printf("in else %d\n", res->val);
             l2 = l2->next;
         }
    }

    if(l1 != NULL){
        while(l1){
            res->val = l1->val;
             res->next = l1->next;
            l1 = l1->next;
        }
    } else{
        while(l2){
            res = l2;
             res->val = l2->val;
                res->next = l2->next;
            l2 = l2->next;
        }
    }

     return res;
}
