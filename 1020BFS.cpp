#include<iostream>
#include<queue>
using namespace std;
int postorder[35],inorder[35],cnt,n;
int flag=0;
typedef struct treenode *tree;
struct treenode 
{
	tree left;
	tree right;
	int num;
};
int frootindex(int rootnum)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(inorder[i]==rootnum)
		{
			return i;
		}
	}
	return -1;
}
tree creat(int start,int end)
{
	if(start>end) return NULL;
	int root=postorder[cnt];
	cnt--;
	int rootindex=frootindex(root);
	tree T=(tree)malloc(sizeof(struct treenode));
	T->num=root;
	if(start==end)
	{
		T->left=NULL;
		T->right=NULL;
	}
	else
	{
		T->right=creat(rootindex+1,end);
		T->left=creat(start,rootindex-1);
	}
	return T;
}
void bfs(tree t)
{
	queue<tree> q;
	q.push(t);
	while(!q.empty())
	{
		tree temp=q.front();
		q.pop();
		if(flag==0)
		{
			flag=1;
			cout<<temp->num;
		}
		else
			cout<<" "<<temp->num;
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
}
int main()
{
	int i;
	cin>>n;
	cnt=n-1;
	for(i=0;i<n;i++)
		cin>>postorder[i];
	for(i=0;i<n;i++)
		cin>>inorder[i];
	tree T=creat(0,cnt);
	bfs(T);
	return 0;
}
