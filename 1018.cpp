#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int inf=9999999;
int map[505][505],dist[505],book[505],bikes[505];
vector<int> pre[505];
vector<int> path,temppath;
int minneed=inf,minback=inf;
void dfs(int v)
{
	if(v==0)
	{
		temppath.push_back(v);
		int need=0,back=0;
		for(int j=temppath.size()-1;j>=0;j--)
		{
			int id=temppath[j];
			if(bikes[id]>0)
			{
				back+=bikes[id];
			}
			else
			{
				if(back>(0-bikes[id]))
				{
					back+=bikes[id];
					
				}
				else
				{
					need+=(-bikes[id]-back);
					back=0;
				}
			}
		}
		if(need<minneed)
		{
			minneed=need;
			minback=back;
			path=temppath;
		}
		else if(need==minneed&&back<minback)
		{
			minback=back;
			path=temppath;
		}
		temppath.pop_back();
		return ;	
	}
	temppath.push_back(v);
	for(int i=0;i<pre[v].size();i++)
		dfs(pre[v][i]);
	temppath.pop_back();
}
int main()
{
	int cmax,n,bad,m,i,j,k;
	memset(map,inf,sizeof(map));
	memset(dist,inf,sizeof(dist));
	cin>>cmax>>n>>bad>>m;
	for(i=1;i<=n;i++)
	{
		cin>>bikes[i];
		bikes[i]=bikes[i]-cmax/2;
	}
	for(i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b]=map[b][a]=c;
	}
	dist[0]=0;
	for(i=0;i<=n;i++)
	{
		int temp=-1,mintemp=inf;
		for(j=0;j<=n;j++)
		{
			if(book[j]==0&&dist[j]<mintemp)
			{
				mintemp=dist[j];
				temp=j;
			}
		}
		book[temp]=1;
		for(k=0;k<=n;k++)
		{
			if(book[k]==0&&map[temp][k]!=inf)
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
	dfs(bad);
	printf("%d ",minneed);
	for(i=path.size()-1;i>=0;i--)
	{
		if(i==path.size()-1) printf("%d",path[i]);
		else printf("->%d",path[i]);
	}
	printf(" %d",minback);
	return 0;
}
