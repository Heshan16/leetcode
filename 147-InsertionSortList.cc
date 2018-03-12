//Solution 1
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode h(0),*p=head;
        while(p) {
            ListNode *pre=&h;
            while(pre->next && pre->next->val<p->val)
                pre=pre->next;
            ListNode *next=p->next;
            p->next=pre->next;
            pre->next=p;
            p=next;
        }
        return h.next;
    }
};


//Solution s2
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode h(0),*p=head;
        h.next=head;
        while(p) {
            ListNode *pre=&h;
            if(p->next && p->next->val<p->val) { //need insert 
                while(pre->next && pre->next->val<p->next->val)
                    pre=pre->next;
                ListNode *temp=pre->next;
                pre->next=p->next;
                p->next=p->next->next;
                pre->next->next=temp;
            }
            else
                p=p->next;
        }
        return h.next;
    }
};
