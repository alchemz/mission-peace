struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

void Serialize(TreeNode *root, vector<int> &output){
	if(root == NULL){
		output.push_back(-1);
		return;
	}

	output.push_back(root->val);
	Serialize(root->left, output);
	Serialize(root->right, output);
}

TreeNode *Deserialize(vector<int> output, int &index){
	if(index > output.size() || output[index]==-1)
		return NULL;

	TreeNode *root = new TreeNode(output[index]);
	index++;
	root->left = Deserialize(output, index);
	index++;
	root->right = Deserialize(output, index);
	return root;
}
//http://fisherlei.blogspot.com/2013/03/interview-serialize-and-de-serialize.html