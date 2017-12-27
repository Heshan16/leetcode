/*
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode **cur=&head;
        while(*cur){
            if(!(*cur)->next || (*cur)->val!=(*cur)->next->val)
                cur=&((*cur)->next);
            else {
                int val=(*cur)->val;
                while(*cur && ((*cur)->val==val)){
                    ListNode *temp=*cur;
                    *cur=(*cur)->next;
                    delete temp;
                }
            }
        }
        return head;
    }
};
