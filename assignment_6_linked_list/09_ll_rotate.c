/**
 * Program to rotate a given linked list upto k places
 *
 * Coded on leetcode
 *
 * @Muskan, 1910990681, 20/08/2021
 * Assignment 6 Linked List, Question 9
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){

    struct ListNode* temp = head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    int len = 0;
    int k_front;
    int i;

    while(temp){
        len++;
        temp = temp->next;
    }

    temp = head;

    printf("len = %d", len);

    k_front = len - k;

    for(i = 0; i < k_front; i++){
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    head = curr;

    for(i = 0; curr->next; i++){
        curr = curr->next;
    }

    curr->next = temp;

    return head;
}
