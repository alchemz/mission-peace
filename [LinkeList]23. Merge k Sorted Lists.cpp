/*
调用mergeTwoLists的函数
注意在mergeKLists的时候，方法类似mergeSort, [0],[1],[2],[3]
[0]位储存每次merge2的结果，从后往前两两合并
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())   return NULL;
        int end = lists.size()-1, start=0;
        while(end>0){
            int start = 0;
            while(start < end){
                lists[start] = mergeTwoLists(lists[start], lists[end]);
                start++;
                end--;
            }
        }
        
        return lists[0];
    }
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur=dummy;
        while(l1&&l2){
            if(l1->val < l2->val){
                cur->next= l1;
                l1=l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur=cur->next;
        }
        
        cur->next = l1? l1:l2;//吸收剩下了的node
        //return dummy;
        return dummy->next;//跳过第一个node
    }
};