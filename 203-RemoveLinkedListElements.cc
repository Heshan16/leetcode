class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode h(0),*p=&h;
        h.next=head;
        while(p->next){
            if(p->next->val==val){
                ListNode *temp=p->next;
                p->next=p->next->next;
                delete temp;
            }
            else
                p=p->next;
        }
        return h.next;
    }
};
