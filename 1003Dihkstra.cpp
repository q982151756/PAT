#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int inf=9999999;
int map[505][505],dis[505],book[505],num[505],w[505];
int main()
{
	int n,m,c1,c2,i,j,k;
	cin>>n>>m>>c1>>c2;
	vector<int> hands(n);
	memset(map,inf,sizeof(map));
	memset(dis,inf,sizeof(dis));
	for(i=0;i<n;i++)
		cin>>hands[i];
	for(i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b]=map[b][a]=c;
	}
	dis[c1]=0;
	w[c1]=hands[c1];
	num[c1]=1;
	for(i=0;i<n;i++)
	{
		int min=inf,temp=-1;
		for(j=0;j<n;j++)
		{
			if(dis[j]<min&&book[j]==0)
			{
				min=dis[j];
				temp=j;
			}
		}
		if(temp==-1) break;
		book[temp]=1;
		for(k=0;k<n;k++)
		{
			if(map[temp][k]!=inf&&book[k]==0)
			{
				if(dis[k]>dis[temp]+map[temp][k])
				{
					dis[k]=dis[temp]+map[temp][k];
					num[k]=num[temp];
					w[k]=w[temp]+hands[k];
				}
				else if(dis[k]==dis[temp]+map[temp][k])
				{
					num[k]=num[k]+num[temp];
					if(w[temp]+hands[k]>w[k])
						w[k]=w[temp]+hands[k];
				}	
			}
		}
		
	}
	printf("%d %d",num[c2],w[c2]);
	return 0;
}

