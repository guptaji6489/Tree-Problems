
#include<iostream>
#include<queue>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data) {
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};
TreeNode* builtTree(TreeNode* root)
{
    int data;
    cin>>data;

    if(data==-1)
    {
        return NULL;
    }
    if(root==NULL)
    {
        root = new TreeNode(data);
    }
    root->left =  builtTree(root->left); // will return me the address of my leftchild node
	root->right =  builtTree(root->right); // will return me the adress of rightchild node

	return root;
}

void levelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {

		TreeNode* node = q.front();
		while(!q.empty())
			    q.pop();

		cout << node->val << " ";

		if (node->left != NULL) {
			q.push(node->left);
		}

		if (node->right != NULL) {
			q.push(node->right);
		}
	}

	cout << endl;
}



int main()
{
    TreeNode* root = NULL;
	root = builtTree(root);

	 cout << "Root value is " << root->val << endl;


	cout << "********* LEVELORDER *******" << endl;
	levelOrder(root);
	cout << endl;

}
//input  -- 8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1

