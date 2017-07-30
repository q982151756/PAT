#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	char id[16];
	int h1,h2;
	int m1,m2;
	int s1,s2;
}a[100];
int cmp1(struct node a,struct node b)
{
	if(a.h1<b.h1) return 1;
	else if(a.h1>b.h1) return 0;
	else if(a.h1==b.h1)
	{
		if(a.m1<b.m1) return 1;
		else if(a.m1>b.m1) return 0;
		else if(a.m1==b.m1)
		{
			if(a.s1<b.s1) return 1;
			else if(a.s1>b.s1) return 0;
			else if(a.s1==b.s1) return 0;
		}
	}
}
int cmp2(struct node a,struct node b)
{
	if(a.h2>b.h2) return 1;
	else if(a.h2<b.h2) return 0;
	else if(a.h2==b.h2)
	{
		if(a.m2>b.m2) return 1;
		else if(a.m2<b.m2) return 0;
		else if(a.m1==b.m1)
		{
			if(a.s2>b.s2) return 1;
			else if(a.s2<b.s2) return 0;
			else if(a.s1==b.s1) return 0;
		}
	}
}
int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
		scanf("%s %d:%d:%d %d:%d:%d",
		a[i].id,&a[i].h1,&a[i].m1,&a[i].s1,
		&a[i].h2,&a[i].m2,&a[i].s2);
	sort(a,a+n,cmp1);
	printf("%s ",a[0].id);
	sort(a,a+n,cmp2);
	printf("%s",a[0].id);
	return 0;
}
