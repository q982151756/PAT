#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> inorder,postorder,preorder;
int count;
struct node
{
	int data;
	node *left;
	node *right;
	node()
	{
		left=right=NULL;
	}
};
int findrootindex(int root)
{
	int i;
	for(i=0;i<inorder.size();i++)
		if(inorder[i]==root)
			break;
	return i;
}
node* creattree(int left,int right)
{
	if(left>right) return NULL;
	int root=preorder[count];
	count++;
	int index=findrootindex(root);
	node* T=new node();
	T->data=root;
	if(left!=right)
	{
		T->left=creattree(left,index-1);
		T->right=creattree(index+1,right);
	}
	return T;
}
bool first=true;
void Postorder(node* T)
{
	if(!T) return ;
	Postorder(T->left);
	Postorder(T->right);
	if(first)
	{
		printf("%d",T->data);
		first=false;
	}
	else
	{
		printf(" %d",T->data);
	}
}
int main()
{
	int n,i,j,t;
	char temp[5];
	stack<int> pp;
	scanf("%d",&n);
	for(i=0;i<2*n;i++)
	{
		scanf("%s",temp);
		if(temp[1]=='u')
		{
			scanf("%d",&t);
			pp.push(t);
			preorder.push_back(t);
		}
		if(temp[1]=='o')
		{
			inorder.push_back(pp.top());
			pp.pop();
		}
	}
	node* T=creattree(0,n-1);
	Postorder(T);
	return 0;
}
