// C++ program to find first leaves that are
// not same.
#include<bits/stdc++.h>
using namespace std;
 
// Tree node
struct Node
{
    int data;
    Node *left,  *right;
};
 
// Utility method to create a new node
Node *newNode(int x)
{
    Node * temp = new Node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}
 
bool isLeaf(Node * t)
{
    return ((t->left == NULL) && (t->right == NULL));
}
 
// Prints the first non-matching leaf node in
// two trees if it exists, else prints nothing.
void findFirstUnmatch(Node *root1, Node *root2)
{
    // If any of the tree is empty
    if (root1 == NULL || root2 == NULL)
      return;
 
    // Create two stacks for preorder traversals
    stack<Node*> s1, s2;
    s1.push(root1);
    s2.push(root2);
 
    while (!s1.empty() || !s2.empty())
    {
        // If traversal of one tree is over
        // and other tree still has nodes.
        if (s1.empty() || s2.empty() )
           return;
 
        // Do iterative traversal of first tree
        // and find first lead node in it as "temp1"
        Node *temp1 = s1.top();
        s1.pop();
        while (temp1 && !isLeaf(temp1))
        {
            // pushing right childfirst so that
            // left child comes first while popping.
            s1.push(temp1->right);
            s1.push(temp1->left);
            temp1 = s1.top();
            s1.pop();
        }
 
        // Do iterative traversal of second tree
        // and find first lead node in it as "temp2"
        Node * temp2 = s2.top();
        s2.pop();
        while (temp2 && !isLeaf(temp2))
        {
            s2.push(temp2->right);
            s2.push(temp2->left);
            temp2 = s2.top();
            s2.pop();
        }
 
        // If we found leaves in both trees
        if (temp1 != NULL && temp2 != NULL )
        {
            if (temp1->data != temp2->data )
            {
                cout << "First non matching leaves : "
                     << temp1->data <<"  "<< temp2->data
                     << endl;
                return;
            }
        }
    }
}
 
// Driver code
int main()
{
    struct Node *root1 = newNode(5);
    root1->left = newNode(2);
    root1->right = newNode(7);
    root1->left->left = newNode(10);
    root1->left->right = newNode(11);
 
    struct Node * root2 = newNode(6);
    root2->left = newNode(10);
    root2->right = newNode(15);
 
    findFirstUnmatch(root1,root2);
 
    return 0;
}
