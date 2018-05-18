/*
1. 讲小于x的node取出，组成新链表
2. 那么，现在剩余的节点会都大于或者等于x
3. 将旧链表接在新链表后面
4. 返回newDummy->next
https://leetcode.com/problems/partition-list/description/
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
    ListNode* partition(ListNode* head, int x) {
        if(!head)   return head;
        
        ListNode *dummy = new ListNode(-1);
        ListNode *newDummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *p = newDummy;
        while(cur->next){
            if(cur->next->val < x){
                p->next = cur->next;
                p = p->next;
                cur->next = cur->next->next;
                p->next = NULL;
            }else{
                cur = cur->next;
            }
        }
        p->next = dummy->next;
        return newDummy->next;
    }
};