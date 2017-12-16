/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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
     ListNode* merge2Lists(ListNode *l1,ListNode *l2) {       
	 ListNode head(0),*cur=&head;
         while(l1 && l2){
                    if(l1->val<=l2->val) {
                        cur->next=l1;
                        l1=l1->next;
                    }
                    else {
                        cur->next=l2;
                        l2=l2->next;
                    }
                    cur=cur->next;
                }
                cur->next=l1?l1:l2;
                return head.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	//In this solution,O(k)=O(k/2)+nk
	//So the Time complexity is(nklogk)
        if(lists.empty())
            return NULL;
        int sz=lists.size()-1;
        while(sz) {
            int i=0,j=sz;
            for(;i<j;i++,j--) {
                lists[i]=merge2Lists(lists[i],lists[j]); 
                lists[j]=NULL;
            }
            sz=min(i,j);
        }
        return lists[0];
    }
    
   
};
