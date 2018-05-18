/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
1. 获得链表长度len
2. 将链表头尾连起来
3. 从头走len - k%len步，断开链表
4. 将断开的下一个node变成新链表头
5. 加上尾部NULL

https://leetcode.com/problems/rotate-list/description/
http://www.cnblogs.com/grandyang/p/4355505.html
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       if(!head) return NULL;
        int len=1;
        ListNode *cur = head;
        while(cur->next){ //获得链表长度
            len++;
            cur=cur->next;
        }
        cur->next = head; //将链表头尾连起来
        int m = len - k%len; 
        for(int i=0; i<m; i++){
            cur = cur->next;
        }
        ListNode *newHead = cur->next;
        cur->next = NULL;
        return newHead;
    }
};