/*
Two Pointers: 
1. 快的先走n步
2. 如果快的走完n步以后发现为空，则删除头
3. 同步更新fast, slow ->next
4. 其他状况则是到达快的到达终点后，删除慢的所在位置
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    //双指针，一个针先走n步，另一个才出发，等到第一个走到终点，第二个就是要删除的点
    //注意头结点的处理，1->2->NULL, n=2, 删除head
    if(!head->next) return NULL;
    ListNode *fast = head, *slow = head;
    for(int i=0; i<n; i++){
        fast = fast->next;//先走n步
    }
    if(!fast) return head->next;//删除头
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;//删除慢的节点所在位置
    return head;
}