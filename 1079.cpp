#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct node
{
	double data;
	vector<int> next;
};
vector<node> mm;
int n;
double pay,r,sum=0.0;
void dfs(int start,int step)
{
	if(mm[start].next.size()==0)
	{
		sum+=mm[start].data*pow(1+r,step);
	}
	else
	{
		for(int i=0;i<mm[start].next.size();i++)
			dfs(mm[start].next[i],step+1);
	}
}
int main()
{
	int i,j;
	scanf("%d %lf %lf",&n,&pay,&r);
	r=r/100;
	mm.resize(n);
	for(i=0;i<n;i++)
	{
		int temp,t;
		scanf("%d",&temp);
		if(temp==0)
			scanf("%lf",&mm[i].data);
		else
		{
			for(j=0;j<temp;j++)
			{
				scanf("%d",&t);
				mm[i].next.push_back(t);
			}
		}
	}
	dfs(0,0);
	printf("%.1lf",sum*pay);
	return 0;
}
