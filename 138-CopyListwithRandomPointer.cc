class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *cur=head;
        while(cur) {
            RandomListNode *cp=new RandomListNode(cur->label);
			cp->next=cur->next;
			cur->next=cp;
			cur=cp->next;
        }
		cur=head;
		while(cur) {
			if(cur->random)
				cur->next->random=cur->random->next;
			cur=cur->next->next;
		}
		RandomListNode h(0),*ch=&h;		
		cur=head;
		while(cur) {
			ch->next=cur->next;
			cur->next=cur->next->next;
			cur=cur->next;
            ch=ch->next;
		}
		ch->next=NULL;
		return h.next;
    }
};
