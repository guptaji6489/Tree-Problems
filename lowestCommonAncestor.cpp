

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


void display(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " -> ";
	}
	cout << endl;
}

void printRootToLeaf(TreeNode* root, vector<int> ans,int a,int b) {
    if(root==NULL)
    {
        return;
    }
    ans.push_back(root->val);
	if (root->val == a or root->val==b) {
            display(ans);
		return;
	}





	printRootToLeaf(root->left, ans,a,b);
	printRootToLeaf(root->right, ans,a,b);
}

int main()
{



     TreeNode* root = NULL;
	root = builtTree(root);

	 cout << "Root value is " << root->val << endl;

   	 vector<int> temp;
	printRootToLeaf(root, temp,7,5);



	 }


	 // input  -->  8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1




