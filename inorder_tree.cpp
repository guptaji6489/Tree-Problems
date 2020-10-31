
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
// Space: O(n)
void inOrder(TreeNode* root) {
	// BASE CASE
	if (root == NULL) {
		return;
	}

	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}


int main()
{



     TreeNode* root = NULL;
	root = builtTree(root);

	 cout << "Root value is " << root->val << endl;


	 cout<<endl<<"--------------------------"<<endl;
	  inOrder(root);
	 cout<<endl;

	 }


	 // input  -->  8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1

