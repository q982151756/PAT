#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,l,h;
struct node
{
	int id,v,t;
};
int cmp(node a,node b)
{
	if(a.v+a.t>b.v+b.t)
		return 1;
	else if(a.v+a.t<b.v+b.t)
		return 0;
	else if(a.v+a.t==b.v+b.t)
	{
		if(a.v>b.v)
			return 1;
		else if(a.v<b.v)
			return 0;
		else if(a.v==b.v)
		{
			return a.id<b.id;
		}
	}
}
int main()
{
	int i,j,num;
	vector<node> sage,nobleman,foolman,smallman;
	scanf("%d%d%d",&n,&l,&h);
	num=n;
	for(i=0;i<n;i++)
	{
		node temp;
		scanf("%d%d%d",&temp.id,&temp.v,&temp.t);
		if(temp.v>=h&&temp.t>=h)
			sage.push_back(temp);
		else if(temp.v>=h&&temp.t>=l)
			nobleman.push_back(temp);
		else if(temp.v>=l&&temp.t>=l&&temp.v>=temp.t)
			foolman.push_back(temp);
		else if(temp.v>=l&&temp.t>=l&&temp.v<temp.t)
			smallman.push_back(temp);
		else if(temp.v<l||temp.t<l)
			num--;
	}
	sort(sage.begin(),sage.end(),cmp);
	sort(nobleman.begin(),nobleman.end(),cmp);
	sort(foolman.begin(),foolman.end(),cmp);
	sort(smallman.begin(),smallman.end(),cmp);
	printf("%d\n",num);
	for(i=0;i<sage.size();i++)
	{
		printf("%08d %d %d\n",sage[i].id,sage[i].v,sage[i].t);
	}
	for(i=0;i<nobleman.size();i++)
	{
		printf("%08d %d %d\n",nobleman[i].id,nobleman[i].v,nobleman[i].t);
	}
	for(i=0;i<foolman.size();i++)
	{
		printf("%08d %d %d\n",foolman[i].id,foolman[i].v,foolman[i].t);
	}
	for(i=0;i<smallman.size();i++)
	{
		printf("%08d %d %d\n",smallman[i].id,smallman[i].v,smallman[i].t);
	}
	return 0;
}
