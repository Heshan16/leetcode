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


//recursive solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode *tail;
        return recur_reverse(head,tail);
    }
    
    ListNode *recur_reverse(ListNode *head,ListNode * &tail) {
        if(!head->next){
            tail=head;
            return head;
        }
        ListNode *newh=recur_reverse(head->next,tail);
        tail->next=head;
        tail=head;
        tail->next=NULL;
        return newh;
    }
};
