#include<iostream>
using namespace std;
int fag[505],a[505][505],n,m,start,end1,j,lg=99999,mx;
int visit[505],shortnum=0;
void dfs(int st,int leg,int max)
{
	if(st==end1)
	{
		if(leg<lg) 
		{
			shortnum=1;
			lg=leg;
			mx=max;
		}
		else if(leg==lg)
		{
			shortnum++;
			if(max>mx) mx=max;
		}
		return;
	}
	if(leg>lg) return;
	visit[st]=1;
	for(int i=0;i<n;i++)
	{
		if(visit[i]==0&&a[st][i]>0)
		{
			//printf("%d %d %d\n",i,leg+a[st][i],max+fag[i]);
			dfs(i,leg+a[st][i],max+fag[i]);
		}
	}
	visit[st]=0;
}
int main()
{
	int i;
	cin>>n>>m>>start>>end1;
	for(i=0;i<n;i++)
		cin>>fag[i];
	for(i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=z;
	}
	dfs(start,0,fag[start]);
	printf("%d %d",shortnum,mx);
}
