/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null. 
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode *cur=head->next,*pre=head->next->next;
        while(pre && pre->next && pre!=cur) {
            pre=pre->next->next;
            cur=cur->next;
        }
        if(!pre || !pre->next)
            return NULL;
        cur=head;
        while(cur!=pre) {
            pre=pre->next;
            cur=cur->next;
        }    
        return cur;
    }
};
