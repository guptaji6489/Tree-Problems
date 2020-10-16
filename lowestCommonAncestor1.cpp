

#include <iostream>
#include <vector>

using namespace std;

class TreeNode{
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


// Time: O(n)
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
	if (root == NULL) {
		return NULL;
	}

	if (root->val == p or root->val == q) {
		return root;
	}

	TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
	TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

	if (leftLCA == NULL and rightLCA == NULL) {
		return NULL;
	}

	if (leftLCA != NULL and rightLCA != NULL) {
		return root;
	}

	// either my leftLCA is null or my rightLCA is null
	if (leftLCA == NULL) {
		return rightLCA;
	} else {
		return leftLCA;
	}
}

int main()
{



     TreeNode* root = NULL;
	root = builtTree(root);

	 cout << "Root value is " << root->val << endl;

	 root = lowestCommonAncestor(root,7,5);

	 cout << "Root value is " << root->val << endl;




	 }


	 // input  -->  8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1





