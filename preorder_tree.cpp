
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


// if there are n nodes in my tree

// Time: O(n)
// Space: O(n)
void preOrder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}



int main()
{



     TreeNode* root = NULL;
	root = builtTree(root);

	 cout << "Root value is " << root->val << endl;

	 preOrder(root);
	 cout<<endl<<"--------------------------"<<endl;


	 }


	 // input  -->  8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1
