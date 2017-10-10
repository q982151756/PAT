#include<iostream>
#include<algorithm>
using namespace std;
long a[100010];
int main()
{
	int n,i,j,max1=0;
	long p;
	scanf("%d%ld",&n,&p);
	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
	sort(a,a+n);
	/*for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");*/
	for(i=0;i<n;i++)
	{
		long temp=a[i]*p;
		int left=i,right=n-1;
		while(left<right)
		{
			int mid=(right+left)/2;
			if(a[mid]<temp)
				left=mid+1;
			else right=mid;
		}
		if(a[right]>temp)
			right-=1;
		//printf("%d %d\n",i,right);
		if(right-i+1>max1)
		{
			max1=right-i+1;	
		}
	}
	printf("%d",max1);
	return 0;
} 
