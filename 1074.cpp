#include<iostream>
#include<vector>
using namespace std;
struct node
{
	int ad;
	int date;
	int next;
}map[100010];
vector<node> aans;
int main()
{
	int first,n,m,i,num,j;
	scanf("%d%d%d",&first,&n,&m);
	for(i=0;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		map[x].date=y;map[x].next=z;map[x].ad=x;
	}
	while(first!=-1)
	{
		aans.push_back(map[first]);
		first=map[first].next;
	}
	int flag=0;
	if(aans.size()%m==0) 
	{
		num=aans.size()/m;
		flag=1;
	}
	else num=aans.size()/m+1;
	vector<vector<node> > ans(num);
	int cnt=0;
	first=aans[0].ad;
	for(i=0;i<num;i++)
	{
		for(j=1;j<=m;j++)
		{
			ans[i].push_back(map[first]);
			first=map[first].next;
			if(first==-1)
				break;
		}
	}
	if(flag==1)
	{
		for(i=0;i<num;i++)
		{
			for(j=m-1;j>=0;j--)
			{
				if(j!=0) printf("%05d %d %05d\n",ans[i][j].ad,ans[i][j].date,ans[i][j-1].ad);
				else if(i==num-1) printf("%05d %d -1\n",ans[i][j].ad,ans[i][j].date);
				else printf("%05d %d %05d\n",ans[i][j].ad,ans[i][j].date,ans[i+1][m-1].ad);
			}
		}
	}
	else if(flag==0)
	{
		for(i=0;i<num;i++)
		{
			if(i!=num-1)
			{
				for(j=m-1;j>=0;j--)
				{
					if(j!=0) printf("%05d %d %05d\n",ans[i][j].ad,ans[i][j].date,ans[i][j-1].ad);
					else if(i!=num-2) printf("%05d %d %05d\n",ans[i][j].ad,ans[i][j].date,ans[i+1][m-1].ad);
					else if(i==num-2) printf("%05d %d %05d\n",ans[i][j].ad,ans[i][j].date,ans[i+1][0].ad);
				}
			}
			if(i==num-1)
			{
				for(j=0;j<ans[i].size();j++)
				{
					if(j!=ans[i].size()-1)
						printf("%05d %d %05d\n",ans[i][j].ad,ans[i][j].date,ans[i][j+1].ad);
					else
						printf("%05d %d -1\n",ans[i][j].ad,ans[i][j].date);
				}
			}
		}
	}
	return 0;
}
