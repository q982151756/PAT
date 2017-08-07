#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int inf=9999999;
int map[505][505],book[505],cost[505][505],dist[505],s;
vector<int> pre[505];
vector<int> path,temppath;
int mincost=inf,tempcost=0;
void dfs(int v,int costs)
{
	tempcost+=costs;
	cout<<v<<" "<<tempcost<<endl;
	if(v==s)
	{
		temppath.push_back(v);
		if(tempcost<mincost)
		{
			mincost=tempcost;
			path=temppath;
		}
		temppath.pop_back();
		return ;
	}
	temppath.push_back(v);
	for(int i=0;i<pre[v].size();i++)
	{
		dfs(pre[v][i],cost[v][pre[v][i]]);
		tempcost-=cost[v][pre[v][i]];
	}
	temppath.pop_back();
}
int main()
{
	int i,j,n,m,e,k;
	cin>>n>>m>>s>>e;
	memset(map,inf,sizeof(map));
	memset(dist,inf,sizeof(dist));
	for(i=0;i<m;i++)
	{
		int a,b,c,t;
		scanf("%d %d %d %d",&a,&b,&c,&t);
		map[a][b]=map[b][a]=c;
		cost[a][b]=cost[b][a]=t;
	}
	dist[s]=0;
	for(i=0;i<n;i++)
	{
		int mintemp=inf,temp=-1;
		for(j=0;j<n;j++)
		{
			if(dist[j]<mintemp&&book[j]==0)
			{
				mintemp=dist[j];
				temp=j;
			}
		}
		book[temp]=1;
		for(k=0;k<n;k++)
		{
			if(map[temp][k]!=inf&&book[k]==0)
			{
				if(dist[temp]+map[temp][k]<dist[k])
				{
					dist[k]=dist[temp]+map[temp][k];
					pre[k].clear();
					pre[k].push_back(temp);
				}
				else if(dist[temp]+map[temp][k]==dist[k])
					pre[k].push_back(temp);
			}
		}
	}
	dfs(e,0);
	for(i=path.size()-1;i>=0;i--)
		printf("%d ",path[i]);
	printf("%d %d",dist[e],mincost);
}
