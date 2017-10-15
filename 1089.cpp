#include<iostream>
#include<algorithm>
using namespace std;
int a[110],b[110];
int main()
{
	int n,i,j,k,l,flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=2;i<=n;i*=2)
	{
		for(j=0,k=i;j<n;j+=i,k+=i)
		{
			if(k>n) k=n;
			sort(a+j,a+k);
		}
		if(flag==1) break;
		for(l=0;l<n;l++)
		{
			if(a[l]!=b[l])
				break;
		}
		if(l==n) flag=1;
	}
	if(flag==0)
	{
		printf("Insertion Sort\n");
		for(i=1;i<n;i++)
		{
			if(b[i]<b[i-1]) break;
		}
		sort(b,b+i+1);
		printf("%d",b[0]);
		for(i=1;i<n;i++)
			printf(" %d",b[i]);
	}	
	if(flag==1)
	{
		printf("Merge Sort\n");
		printf("%d",a[0]);
		for(i=1;i<n;i++)
			printf(" %d",a[i]);
	}
	return 0;
}
