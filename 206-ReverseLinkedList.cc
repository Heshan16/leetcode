class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newh=NULL;
        while(head) {
            ListNode *temp=head;
            head=head->next;
            temp->next=newh;
            newh=temp;
        }
        return newh;
    }
};
