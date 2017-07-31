#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct one
{
	float x;
	int y;
}n1[11],n2[11];
int cmp(struct one a,struct one b)
{
	return a.y>b.y?1:0;
}
vector<struct one> re;
int main()
{
	int k1,k2,i,j,sum,k;
	cin>>k1;
	for(i=0;i<k1;i++)
		cin>>n1[i].y>>n1[i].x;
	cin>>k2;
	for(i=0;i<k2;i++)
		cin>>n2[i].y>>n2[i].x;
	sum=k1*k2;
	for(i=0;i<k1;i++)
	{
		for(j=0;j<k2;j++)
		{
			struct one t;
			t.x=n1[i].x*n2[j].x;
			t.y=n1[i].y+n2[j].y;
			for(k=0;k<re.size();k++)
			{
				if(re[k].y==t.y)
				{
					re[k].x+=t.x;
					sum--;
					break;
				}
			}
			if(k==re.size())
				re.push_back(t);
		}
	}
	sort(re.begin(),re.end(),cmp);
	for(i=0;i<re.size();i++)
	{
		if(re[i].x==0)
			sum--;
	}
	printf("%d",sum);
	for(i=0;i<re.size();i++)
	{
		if(re[i].x!=0)
			printf(" %d %.1f",re[i].y,re[i].x);
	}
	return 0;
}
