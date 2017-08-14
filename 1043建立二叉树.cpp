#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
struct node
{
	node *left;
	node *right;
	int date;
};
node* creat(int v)
{
	node* h=new node();
	h->left=h->right=NULL;
	h->date=v;
	return h;
}
node* insert1(node *t1,int t)
{
	if(t1==NULL)
		return creat(t);
	else
	{
		if(t<t1->date)
			t1->left=insert1(t1->left,t);
		else
			t1->right=insert1(t1->right,t);
	}
	return t1;
}
node* insert2(node *t2,int t)
{
	if(t2==NULL)
		return creat(t);
	else
	{
		if(t>=t2->date)
			t2->left=insert2(t2->left,t);
		else
			t2->right=insert2(t2->right,t);
	}
	return t2;
}
void preorder(node *t, vector<int> &v)
{
	v.push_back(t->date);
	if(t->left) preorder(t->left,v);
	if(t->right) preorder(t->right,v);
}
void postorder(node *t,vector<int> &re)
{
	if(t->left) postorder(t->left,re);
	if(t->right) postorder(t->right,re);
	re.push_back(t->date);
}
int main()
{
	int n,i,j,t;
	node *t1=NULL,*t2=NULL;
	scanf("%d",&n);
	vector<int> v,v1,v2,re;
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		v.push_back(t);
		t1=insert1(t1,t);
		t2=insert2(t2,t);	
	}
	preorder(t1,v1);
	preorder(t2,v2);
	if(v1==v)
	{
		printf("YES\n");
		postorder(t1,re);
		printf("%d",re[0]);
		for(i=1;i<re.size();i++)
			printf(" %d",re[i]);
	}
	else if(v2==v)
	{
		printf("YES\n");
		postorder(t2,re);
		printf("%d",re[0]);
		for(i=1;i<re.size();i++)
			printf(" %d",re[i]);
	}
	else
		printf("NO");
	printf("\n");
	return 0;
}
