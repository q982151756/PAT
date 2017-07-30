#include<iostream>
#include<algorithm>
using namespace std;
struct fs
{
	int x;
	float c;
}a1[11],a2[11],re[22];
int cmp(struct fs a,struct fs b)
{
	return a.x>b.x?1:0;
}
int main()
{
	int k1,k2,i,j,sum,k;
	cin>>k1;
	for(i=0;i<k1;i++)
	{
		cin>>a1[i].x>>a1[i].c;
		re[i]=a1[i];
	}
	j=i;
	cin>>k2;
	for(i=0;i<k2;i++)
		cin>>a2[i].x>>a2[i].c;
	sum=k1+k2;
	for(i=0;i<k2;i++)
	{
		for(k=0;k<j;k++)
		{
			if(a2[i].x==re[k].x)
			{
				re[k].c+=a2[i].c;
				sum--;
				break;
			}
		}
		if(k==j)
		{
			re[j]=a2[i];
			j++;
		}
	}	
	sort(re,re+sum,cmp);
	int t=sum;
	for(i=0;i<t;i++)
	{
		if(re[i].c==0)
		{
			sum--;
		}
	}
	printf("%d",sum);
	for(i=0;i<t;i++)
	{
		if(re[i].c!=0)
			printf(" %d %.1f",re[i].x,re[i].c);
		else
			continue;
	}
	return 0;
}
