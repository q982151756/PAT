#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int cmp1(long long a,long long b)
{
	return a>b;
}
int cmp2(long long a,long long b)
{
	return a<b;
}
int main()
{
	int n,m,i,j;
	long long temp,num=0;
	scanf("%d",&n);
	vector<long long> znc,fnc;
	vector<long long> znp,fnp;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&temp);
		if(temp<0) fnc.push_back(temp);
		else znc.push_back(temp);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld",&temp);
		if(temp<0) fnp.push_back(temp);
		else znp.push_back(temp);
	}
	sort(znc.begin(),znc.end(),cmp1);
	sort(znp.begin(),znp.end(),cmp1);
	sort(fnc.begin(),fnc.end(),cmp2);
	sort(fnp.begin(),fnp.end(),cmp2);
	for(i=0;i<znc.size()&&i<znp.size();i++)
	{
		num+=znc[i]*znp[i];
	}
	for(i=0;i<fnc.size()&&i<fnp.size();i++)
	{
		num+=fnc[i]*fnp[i];
	}
	printf("%lld",num);
	return 0;
}
