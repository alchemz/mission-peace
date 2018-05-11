/*
Reverse LinkedList
*/
/*
思路是在原链表之前建立一个dummy node，因为首节点会变，然后从head开始，
将之后的一个节点移到dummy node之后，重复此操作知道head成为末节点为止
*/
struct ListNode{
	ListNode* next;
	int val;
	ListNode(int x): val(x), next(NULL){}
};

ListNode* reverseList(ListNode* head){
	if(head==NULL){
		return head;
	}
	ListNode* dummy = new ListNode(-1);

	dummy ->next = head;
	while(cur->next){
		ListNode* tmp = cur->next;
		cur->next = tmp->next;
		tmp->next = dummy->next;
		dummy->next = tmp;
	}
	return dummy->next;
}