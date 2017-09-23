#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int date;
	node *left;
	node *right;
};
int getweight(node* root)
{
	if(root==NULL)	return 0;
	return max(getweight(root->left),getweight(root->right))+1;
}
node* leftleft(node *root)
{
	node *t=root->left;
	root->left=t->right;
	t->right=root;
	return t;
}
node* rightright(node *root)
{
	node *t=root->right;
	root->right=t->left;
	t->left=root;
	return t;
}
node* leftright(node *root)
{
	root->left=rightright(root->left);
	return leftleft(root);
}
node* rightleft(node *root)
{
	root->right=leftleft(root->right);
	return rightright(root);
}
node* insert(node* root,int val)
{
	if(root==NULL)
	{
		root=new node;
		root->date=val;
		root->left=root->right=NULL;
	}
	else if(val<root->date)
	{
		root->left=insert(root->left,val);
		if(getweight(root->left)-getweight(root->right)==2)
		{
			root=val<root->left->date?leftleft(root):leftright(root);
		}
	}
	else
	{
		root->right=insert(root->right,val);
		if(getweight(root->left)-getweight(root->right)==-2)
		{
			root=val>root->right->date?rightright(root):rightleft(root);
		}
	}
	return root;
}
int main()
{
	int n,val;
	node *root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&val);
		root=insert(root,val);
	}
	printf("%d",root->date);
	return 0;
} 
