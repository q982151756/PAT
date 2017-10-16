#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct node
{
	vector<int> children;
};
int n,root,i,count,num;
double p,r;
vector<node> mm;
void dfs(int start,int step)
{
	cout<<mm[start].children.size()<<endl;
	if(mm[start].children.size()==0)
	{
		if(step>count)
		{
			count=step;
			num=1;
		}
		else if(step==count)
		{
			num++;
		}
		return ;
	}
	for(int j=0;j<mm[start].children.size();j++)
	{
		dfs(mm[start].children[j],step+1);
	}
}
int main()
{
	double ans=0.0;
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;
	mm.resize(n);
	for(i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(temp==-1) root=i;
		else
			mm[temp].children.push_back(i);
	}
	dfs(root,0);
	ans=p*pow(1+r,count);
	printf("%.2lf %d\n",ans,num);
	return 0;
}
