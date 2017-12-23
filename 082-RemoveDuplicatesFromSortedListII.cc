/*
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode h(0),*p=&h;
        while(head) {
            if(!head->next || head->next->val!=head->val) {
                p->next=head;
                p=p->next;
                head=head->next;
            }
            else {
                int val=head->val;
                while(head && head->val==val){
                    ListNode *temp=head;
                    head=head->next;
                  delete temp;
                }
                //p->next=head;
                //p=p->next;
            }
        }
        return h.next;
    }
};
