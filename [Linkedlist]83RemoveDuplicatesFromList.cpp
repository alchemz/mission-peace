#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head) {
        if(!head) return head;
        ListNode *cur = head;
        while(cur->next) {
            if(cur->val == cur->next->val) {
                ListNode *temp = cur->next;
                cur->next = temp->next;
                delete temp;
            }
            else {
                cur = cur->next;
            }
        }
        return head;        
}

void printList(ListNode* h)
{
    while(h!=NULL){
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\n");
}

ListNode* createList(int a[], int n)
{
    ListNode *head=NULL, *p=NULL;
    for(int i=0; i<n; i++){
        if (head == NULL){
            head = p = new ListNode(a[i]);
        }else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}


int main()
{
    int a[]={1,1,2,3,3};
    //int b[]={1,1,1};

    printList(deleteDuplicates(createList(a, sizeof(a)/sizeof(int))));
    //printList(deleteDuplicates(createList(b, sizeof(b)/sizeof(int))));
    return 0;
}

    
