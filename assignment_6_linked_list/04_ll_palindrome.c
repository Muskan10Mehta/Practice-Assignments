/**
 * Program to find if the given silngly linked list is palindome or not
 *
 * Coded on Leetcode
 *
 * @Muskan, 1910990681, 23/08/2021
 * Assignment 6 Linked List, Question 4
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){

    int  i = 0;
    int first;
    int end;
    
    // save the first value
    first = head->val;

    // loop to find the end of the linked list
    for(i = 0; head->next!= NULL; i++){
        head = head->next;
    }
   
    // save value of last element
    end = head->val;

    // if first and end are equal its a palindrome
    if(first == end){
        return true;
    }else{
        return false;
    }

}
