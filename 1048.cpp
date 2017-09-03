#include<iostream>
#include<algorithm>
using namespace std;
int a[100001];
int main()
{
	int n,m,i,j,ans1=0,ans2=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(i=0;i<n-1;i++)
	{
		int left=i+1,right=n-1,mid;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(a[i]+a[mid]==m)
			{
				ans1=a[i];ans2=a[mid];
				break;
			}
			else if(a[i]+a[mid]<m)
				left=mid+1;
			else if(a[i]+a[mid]>m)
				right=mid-1;
		}
		if(ans1!=0&&ans2!=0) break;
	}
	if(ans1==0&&ans2==0) printf("No Solution");
	else printf("%d %d",ans1,ans2);
	return 0;
}
