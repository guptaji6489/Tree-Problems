


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


// in a tree problem you are just given a root node

// Time: O(n)
// Space: O(n)
int height(TreeNode* root) {
	//BASE CASE
	if (root == NULL) {
		return -1;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int totalHeight = max(leftHeight, rightHeight) + 1;
	return totalHeight;
}

void kthnode(TreeNode* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==1)
    {
        cout<<root->val<<" ";
        return;
    }
    kthnode(root->left,k-1);
    kthnode(root->right,k-1);
    return;
}

int main()
{



     TreeNode* root = NULL;
	root = builtTree(root);

	 cout << "Root value is " << root->val << endl;

   	 	cout << "Height of the tree is " << height(root) << endl;
    kthnode(root,3);


	 }


	 // input  -->  8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1




