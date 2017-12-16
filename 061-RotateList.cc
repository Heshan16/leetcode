/*
Given a list, rotate the list to the right by k places, where k is non-negative.

Example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.
/*

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode *pre=head,*follow=head;   
        for(int i=0;i<k;i++) {
            if(!(pre->next)){
                k=k%(i+1);
                i=-1;
            }
            pre=pre->next?pre->next:head;
        }
        while(pre->next) {
            pre=pre->next;
            follow=follow->next;
        }
        pre->next=head;
        head=follow->next;
        follow->next=NULL;
        return head;
    }   
};
