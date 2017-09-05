#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,weights,sum=0;
vector<long> we(100);
struct node
{
	vector<int> children;	
}map[100];
vector<vector<int> > allans;
vector<int> temp;
void dfs(int s)
{
	sum+=we[s];
	temp.push_back(we[s]);
	if(map[s].children.size()==0)
	{
		if(sum==weights)
		{
			allans.push_back(temp);
		}
		temp.pop_back();
		sum-=we[s];
		return ;
	}
	for(int i=0;i<map[s].children.size();i++)
	{
		dfs(map[s].children[i]);
	}
	temp.pop_back();
	sum-=we[s];
	return ;
}
int cmp(vector<int> a,vector<int> b)
{
	int i;
	for(i=0;i<a.size()&&i<b.size();i++)
	{
		if(a[i]==b[i]) ;
		else if(a[i]>b[i]) return 1;
		else return 0;
	}
	if(i==a.size()||i==b.size())
		return a.size()>b.size();
}
int main()
{
	int i,j;
	scanf("%d%d%d",&n,&m,&weights);
	for(i=0;i<n;i++)
		scanf("%d",&we[i]);
	for(i=0;i<m;i++)
	{
		int x,y,z;
		scanf("%d%d",&x,&y);
		for(j=0;j<y;j++)
		{
			scanf("%d",&z);
			map[x].children.push_back(z);
		}
	}
	dfs(0);
	sort(allans.begin(),allans.end(),cmp);
	for(i=0;i<allans.size();i++)
	{
		for(j=0;j<allans[i].size();j++)
		{
			if(j==0) printf("%d",allans[i][j]);
			else printf(" %d",allans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
