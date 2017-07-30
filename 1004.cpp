#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[100];
int maxdepth=-1,book[100];
int n,m,node,k;
void dfs(int index,int depth)
{
	if(v[index].size()==0)
	{
		book[depth]++;
		maxdepth=max(maxdepth,depth);
		printf("%d %d\n",depth,maxdepth);
		return;
	}
	for(int i=0;i<v[index].size();i++)
	{
		dfs(v[index][i],depth+1);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>node>>k;
		for(int j=0;j<k;j++)
		{
			int c;
			cin>>c;
			v[node].push_back(c);
		}
	}
	dfs(1,0);
	printf("%d",book[0]);
	for(int i=1;i<=maxdepth;i++)
		printf(" %d",book[i]);
	return 0;
} 
