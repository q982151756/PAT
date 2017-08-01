#include<iostream>
#include<cstring>
using namespace std;
int map[1000][1000];
int visit[1001];
int n,m,k;
void dfs(int x)
{
	visit[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(visit[i]==0&&map[x][i]==1)
			dfs(i);
	}
}
int main()
{
	int i,j;
	cin>>n>>m>>k;
	for(i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		map[a][b]=map[b][a]=1;
	}
	while(k--)
	{
		memset(visit,0,sizeof(visit));
		int temp,sum=0;
		cin>>temp;
		visit[temp]=1;
		for(i=1;i<=n;i++)
		{
			if(visit[i]==0)
			{
				dfs(i);
				sum++;
			}
		}
		cout<<sum-1<<endl;
	}
	return 0;
}
