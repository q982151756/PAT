#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int size,n,i,j;
	scanf("%d%d",&size,&n);
	if(size==1) size=2;
	else
	for(i=size;;i++)
	{
		int temp=sqrt(i);
		for(j=2;j<=temp;j++)
		{
			if(i%j==0) break;
		}
		if(j>temp)
		{
			size=i;
			break;
		}
	}
	vector<bool> ans(size,false);
	
	for(i=0;i<n;i++)
	{
		int t,p;
		scanf("%d",&t);
		p=t%size;
		if(ans[p]==false)
		{
			ans[p]=true;
			if(i==0) printf("%d",p);
			else printf(" %d",p);
		}
		else
		{
			int count=1;
			while(count<size)
			{
				if(ans[(p+count*count)%size]==false)
				{
					ans[(p+count*count)%size]=true;
					if(i==0) printf("%d",(p+count*count)%size);
					else printf(" %d",(p+count*count)%size);
					break;
				}
				count+=1;
			}
			if(count>=size)
			{
				if(i==0) printf("-",p);
				else printf(" -",p);		
			}		
		}
	}
	return 0;
}
