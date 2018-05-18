
/*
https://leetcode.com/problems/add-two-numbers/description/
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Explanation: 342 + 465 = 807.
*/
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    int carry=0;
    ListNode* dummy= new ListNode(0);
    ListNode* p=dummy;
    while(l1 || l2 || carry){
        if(l1){
            carry += l1->val;
            l1=l1->next;
        }
        if(l2){
            carry += l2->val;
            l2=l2->next;
        }
        p->next= new ListNode(carry%10);
        carry = carry/10;
        p=p->next;
    }
    
    return dummy->next;
}
ListNode *create_linkedlist(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur=head; iter != lst.end(); cur=cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

int main(){
    ListNode* l1=create_linkedlist({5,6,3});
    ListNode* l2=create_linkedlist({8,4,2});
    ListNode* res=addTwoNumbers(l1, l2);
    
    while(res != NULL){
        cout<<res->val;
        res=res->next;
    }   
    return 0;
}
        
