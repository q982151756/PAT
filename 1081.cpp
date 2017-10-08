#include<iostream>
using namespace std;
struct node
{
	long x,y;
};
long get(long x,long y)
{
	long temp;
	while(y)
	{
		temp=x;
		x=y;
		y=temp%y;
	}
	return x;
}
int main()
{
	node ans;
	char flag;
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		long a,b;
		scanf("%ld/%ld",&a,&b);
		if(i==0)
		{
			ans.x=a;ans.y=b;
		}
		else
		{
			ans.x=ans.x*b+a*ans.y;
			ans.y=ans.y*b;
		}
	}
	if(ans.x==0) printf("0");
	else
	{
		if(ans.x<0) 
		{
			flag='-';
			ans.x=-ans.x;
		}
		else flag='+';
		long temp=get(ans.x,ans.y);
		ans.x=ans.x/temp;
		ans.y=ans.y/temp;
		long intger=ans.x/ans.y;
		ans.x=ans.x%ans.y;
		if(intger==0)
		{
			if(flag=='-')
				printf("%c%ld/%ld",flag,ans.x,ans.y);
			else printf("%ld/%ld",ans.x,ans.y);
		}
		else if(ans.x==0)
		{
			if(flag=='-') printf("%c%ld",flag,intger);
			else printf("%ld",intger);
		}
		else if(intger!=0&&ans.x!=0)
		{
			if(flag=='-') printf("%c%ld %ld/%ld",flag,intger,ans.x,ans.y);
			else printf("%ld %ld/%ld",intger,ans.x,ans.y);
		}
	}	
	
	return 0;
}
