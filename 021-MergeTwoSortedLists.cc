/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0),*cur=&head;
        while(l1 && l2) {
            if(l1->val<=l2->val){
                cur->next=l1;
                l1=l1->next;
            }
            else {
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;//此句别忘了．．．
        }
        cur->next=l1?l1:l2;
        return head.next;
    }
};
