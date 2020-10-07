
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
int countNodes(TreeNode* root) {
	//BASE CASE
	if (root == NULL) {
		return 0;
	}

	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);

	int totalCount = leftCount + root->val + rightCount;
	return totalCount;
}

int countn(TreeNode* root)
{
    static int c=0;
    if(root==NULL)
    {
        return 0;
    }
    if(1)
    {
         c = c+root->val;

    }
    countn(root->left);
    countn(root->right);




return c;
}

int main()
{



     TreeNode* root = NULL;
	root = builtTree(root);

	 cout << "Root value is " << root->val << endl;

   	 cout << "Total number of nodes " << countNodes(root) << endl;
   	 cout << "Total number of nodes sum  " << countn(root) << endl;



	 }


	 // input  -->  8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1



