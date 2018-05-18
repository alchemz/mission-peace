/*
bool dup=false;
注意利用if(dup)删除重复出现的node
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode * pre = dummy, *cur = head;
        bool dup=false;
        while(cur){
            if(cur->next && cur->val == cur->next->val){
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                dup = true;
            }
            else if(dup){
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
                dup = false;
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};