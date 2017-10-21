#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node
{
	int rank;
	vector<int> children;
};
int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	vector<node> a(n+1);
	for(i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for(j=0;j<y;j++)
		{
			int temp;
			scanf("%d",&temp);
			a[x].children.push_back(temp);
		}
	}
	vector<int> ans(n+1);
	queue<int> q;
	q.push(1);
	a[1].rank=1;
	while(!q.empty())
	{
		int t=q.front();
		ans[a[t].rank]++;
		q.pop();
		for(i=0;i<a[t].children.size();i++)
		{
			a[a[t].children[i]].rank=a[t].rank+1;
			q.push(a[t].children[i]);
		}
	}
	int maxnum=0,maxrank;
	for(i=1;i<=n;i++)
	{
		if(ans[i]>maxnum)
		{
			maxnum=ans[i];
			maxrank=i;
		}
	}
	printf("%d %d\n",maxnum,maxrank);
	return 0;
}
