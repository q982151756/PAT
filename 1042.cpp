#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	char x;
	int y;
	int post;
}a[55];
int b[55];
int cmp(struct node a,struct node b)
{
	return a.post<b.post;
}
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=54;i++)
		scanf("%d",&b[i]);
	j=1;
	for(i=1;i<=54;i++)
	{
		if(j%14==0) j=1;
		if(i<=13)
		{
			a[i].x='S';
			a[i].y=j;
			j++;
		}
		else if(i<=26)
		{
			a[i].x='H';
			a[i].y=j;
			j++;
		}
		else if(i<=39)
		{
			a[i].x='C';
			a[i].y=j;
			j++;
		}
		else if(i<=52)
		{
			a[i].x='D';
			a[i].y=j;
			j++;
		}
		else
		{
			a[i].x='J';
			a[i].y=j;
			j++;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<55;j++)
		{
			a[j].post=b[j];
		}
		sort(a+1,a+55,cmp);		
	}
	for(i=1;i<55;i++)
	{
		if(i==1)	printf("%c%d",a[i].x,a[i].y);
		else	printf(" %c%d",a[i].x,a[i].y);
	}
	return 0;
}
