/*
从head开始，把每个节点移动到dummy后面，重复知道head成为末节点
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
    ListNode* reverseList(ListNode* head) {
        if(!head)   return head;
        ListNode *pre = new ListNode(-1);
        pre->next = head;
        ListNode *cur = head;
        while(cur->next){
            ListNode *tmp = cur->next; //tmp指向目前正在处理的节点
            cur->next = tmp->next; //cur指向目前处理的节点的下一个节点
            tmp->next = pre->next;//原链表第一个节点成为倒置的最后一个节点
            pre->next = tmp;//插入单链表后面
        }
        return pre->next;
    }
};