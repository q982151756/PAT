#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int inf=9999999;
int n,m,k,ds,ansid=-1;
float ansdis=-1,ansavr=inf;
int map[1020][1020],dis[1020];
bool visit[1020];
int main()
{
	memset(map,inf,sizeof(map));
	memset(visit,false,sizeof(visit));
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	for(int i=0;i<k;i++)
	{
		string a,b;
		int diss,x,y;
		cin>>a>>b>>diss;
		if(a[0]=='G')
		{
			a=a.substr(1);
			x=n+stoi(a);
		}
		else
		{
			x=stoi(a);
		}
		if(b[0]=='G')
		{
			b=b.substr(1);
			y=n+stoi(b);
		}
		else
		{
			y=stoi(b);
		}
		map[x][y]=map[y][x]=diss;
	}
	for(int i=n+1;i<=n+m;i++)
	{
		memset(dis,inf,sizeof(dis));
		memset(visit,false,sizeof(visit));
		float tempdis=inf,tempavr=0;
		dis[i]=0;
		for(int j=0;j<n+m;j++)
		{
			int index=-1,minn=inf;
			for(int u=1;u<=n+m;u++)
			{
				if(visit[u]==false&&dis[u]<minn)
				{
					index=u;
					minn=dis[u];
				}
			}
			if(index==-1) break;
			visit[index]=true;
			for(int v=1;v<=n+m;v++)
			{
				if(visit[v]==false&&dis[v]>dis[index]+map[index][v])
					dis[v]=dis[index]+map[index][v];
			}
		}
		for(int q=1;q<=n;q++)
		{
			if(dis[q]>ds)
			{
				tempdis=-1;
				break;
			}
			if(tempdis>dis[q]) tempdis=dis[q];
			tempavr+=1.0*dis[q];
		}
		if(tempdis==-1) continue;
		tempavr/=n;

		if(tempdis>ansdis)
		{
			ansid=i;
			ansdis=tempdis;
			ansavr=tempavr;
		}
		else if(tempdis==ansdis&&tempavr<ansavr)
		{
			ansid=i;
			ansavr=tempavr;
		}
	}
	if(ansid==-1)	printf("No Solution");
	else
	{
		printf("G%d\n",ansid-n);
		printf("%.1f %.1f",ansdis,ansavr);	
	}
}
