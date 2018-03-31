class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *cur=head;
        int i;
        for(i=0;cur;i++)
            cur=cur->next;
        
        if(i<2)
            return;
        cur=head;
        for(i/=2;i>1;i--)
            cur=cur->next;     
        //reverse n/2--n node
        ListNode *movh=cur,*pren=cur->next;
        //insert pren->next after movh
        while(pren->next) {
            ListNode *temp=pren->next;
            pren->next=temp->next;
            temp->next=movh->next;
            movh->next=temp;
        }


        ListNode *pre=head,*follow=cur;
        while(follow!=pre) {
            ListNode *temp=follow->next;
            follow->next=temp->next;
            temp->next=pre->next;
            pre->next=temp;
            pre=temp->next;
        }
    }
};
