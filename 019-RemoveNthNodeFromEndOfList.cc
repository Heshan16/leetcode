/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode **p=&head,*pre=head;
        for(int i=1;i<n;i++)
            pre=pre->next;
        while(pre->next) {
            p=&((*p)->next);
            pre=pre->next;
        }
        ListNode *t=*p;
        (*p)=(*p)->next;
        delete t;
        return head;
    }
};
