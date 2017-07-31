#include<iostream>
using namespace std;
int a[10005];
int main()
{
	int n,i,j,re=-1,sum=0,b,e;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		if(sum>=0)
			sum+=a[i];
		if(sum<0)
		{
			sum=a[i];
		}
		if(sum>re)
		{
			re=sum;
			e=i;
		}
	}
	int temp=0;
	for(i=e;i>=0;i--)
	{
		temp+=a[i];
		if(temp==re)
			b=i;
	}
	if(re>=0)
		printf("%d %d %d",re,a[b],a[e]);
	else if(re<0)
		printf("0 %d %d",a[0],a[n-1]);
	return 0;
}
