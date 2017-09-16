#include<iostream>
#include<set>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	set<int> ss[n+1];
	for(int i=1;i<=n;i++)
	{
		int num;
		scanf("%d",&num);
		for(int j=0;j<num;j++)
		{
			int temp;
			scanf("%d",&temp);
			ss[i].insert(temp);
		}
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int sum=ss[y].size(),ssum=0;
		for(auto it=ss[x].begin();it!=ss[x].end();it++)
		{
			if(ss[y].find(*it)==ss[y].end())
			{
				sum++;
			}
			else
			{
				ssum++;
			}
		}
		float ans=(float)ssum/sum*100;
		//printf("%d %d\n",sum,ssum);
		printf("%.1f%\n",ans);
	}
	return 0;
}
