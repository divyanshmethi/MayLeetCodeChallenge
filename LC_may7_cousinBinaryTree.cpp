#include<iostream>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int l) : val(l), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isCousin(TreeNode* root,int x,int y)
{
	if(root==NULL)
	{
		return false;
	}
	TreeNode* parentX = NULL,*parentY = NULL;
	queue<pair<TreeNode*,TreeNode*>> q;
	TreeNode* temp = new TreeNode(-1);
	q.push(make_pair(root,temp));
	pair<TreeNode*,TreeNode*> ele;
	int level;
	while(!q.empty())
	{
		level = q.size();
		while(level)
		{
			ele = q.front();
			q.pop();
			if(ele.first->val == x)
			{
				parentX = ele.second;
			}
			if(ele.first->val == y)
			{
				parentY = ele.second;
			}
			if(ele.first->left)
			{
				q.push(make_pair(ele.first->left,ele.first));
			}
			if(ele.first->right)
			{
				q.push(make_pair(ele.first->right,ele.first));
			}
			level--;
			if(parentX && parentY)
			{
				break;
			}
		}
		if(parentX && parentY)
		{
			return (parentX != parentY);
		}
		if((parentX && !parentY) || (!parentX && parentY))
		{
			return false;
		}
		return true;
	}
}

int main()
{
	struct TreeNode *root = new TreeNode(1); 
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(5); 
    root->left->right->right = new TreeNode(15); 
    root->right->left = new TreeNode(6); 
    root->right->right = new TreeNode(7); 
    root->right->left->right = new TreeNode(8); 
    struct TreeNode *Node1,*Node2; 
    Node1 = root->left->left; 
    Node2 = root->right->right; 
    
    if(isCousin(root,Node1->val,Node2->val))
    {
    	cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
  	cout<<endl;
}
