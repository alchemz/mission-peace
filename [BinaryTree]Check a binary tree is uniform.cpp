// C++ program to find count of single valued subtrees
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left, *right;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return (temp);
}


bool is_uniform(Node *root){
    if(root==NULL)  return true;
    bool is_left_uni = is_uniform(root->left);
    bool is_right_uni = is_uniform(root->right);
    if(is_left_uni && is_right_uni && 
    ((root->left==NULL) || root->left->data==root->data) && 
    ((root->right==NULL) || root->right->data ==root->data)){
        return true;
    }else{
        return false;
    }
}

int main()
{
	Node* root	 = newNode(5);
	root->left	 = newNode(5);
	root->right	 = newNode(5);
	root->left->left = newNode(5);
	root->left->right = newNode(5);
	root->right->right = newNode(5);

	if(is_uniform(root)){
	    cout<<"Yes, it is uniform tree";
	}else{
	    cout<<"No, it is not.";
	}
	return 0;
}
