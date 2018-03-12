/*
 Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 
*/

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
    bool hasCycle(ListNode *head) {
        ListNode *follow=head;
        while(head && head->next) {
            head=head->next->next;
            follow=follow->next;
            if(head==follow)
                return true;
        }
        return false;
    }
};
