#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	float count;
	float pay;
	float avr;
}a[1005];
int cmp(node a,node b)
{
	return a.avr>b.avr;
}
int main()
{
	int n,i;
	float m,ans=0;
	scanf("%d%f",&n,&m);
	for(i=0;i<n;i++)
		scanf("%f",&a[i].count);
	for(i=0;i<n;i++)
	{
		scanf("%f",&a[i].pay);
		a[i].avr=a[i].pay/a[i].count;
	}
	sort(a,a+n,cmp);
	for(i=0;i<n;i++)
	{
		if(a[i].count<=m)
		{
			ans+=a[i].pay;
			m-=a[i].count;
		}
		else if(a[i].count>m)
		{
			ans+=(a[i].avr*m);
			m=0;
		}
		if(m==0) break;	
	}
	printf("%.2f",ans);
	return 0;
}
