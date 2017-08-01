#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct student
{
	string id;
	int c;
	int m;
	int e;
	int aver;
}s[2001];
int cmpa(struct student a,struct student b)
{
	return a.aver>b.aver?1:0;
}
int cmpc(struct student a,struct student b)
{
	return a.c>b.c?1:0;
}
int cmpm(struct student a,struct student b)
{
	return a.m>b.m?1:0;
}
int cmpe(struct student a,struct student b)
{
	return a.e>b.e?1:0;
}
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>s[i].id>>s[i].c>>s[i].m>>s[i].e;
		s[i].aver=(s[i].c+s[i].m+s[i].e)/3;
	}
	while(m--)
	{
		int acme[4]={0};
		char Acme[]={'A','C','M','E'};
		string t;
		cin>>t;
		for(i=0;i<n;i++)
		{
			if(s[i].id==t)
				break;
		}
		if(i==n)
		{
			cout<<"N/A"<<endl;
			continue;
		}
		sort(s,s+n,cmpa);
		for(i=0;i<n;i++)
		{
			if(s[i].id==t)
			{
				int x=i;
				for(;x>=0;x--)
				{
					if(s[x].aver!=s[i].aver)
						break;
				}
				if(x>=0) acme[0]=x+1;
				if(x<0) acme[0]=0;			
			}
		}
		sort(s,s+n,cmpc);
		for(i=0;i<n;i++)
		{
			if(s[i].id==t)
			{
				int x=i;
				for(;x>=0;x--)
				{
					if(s[x].c!=s[i].c)
						break;
				}
				if(x>=0) acme[1]=x+1;
				if(x<0) acme[1]=0;			
			}
		}
		sort(s,s+n,cmpm);
		for(i=0;i<n;i++)
		{
			if(s[i].id==t)
			{
				int x=i;
				for(;x>=0;x--)
				{
					if(s[x].m!=s[i].m)
						break;
				}
				if(x>=0) acme[2]=x+1;
				if(x<0) acme[2]=0;			
			}
		}
		sort(s,s+n,cmpe);
		for(i=0;i<n;i++)
		{
			if(s[i].id==t)
			{
				int x=i;
				for(;x>=0;x--)
				{
					if(s[x].e!=s[i].e)
						break;
				}
				if(x>=0) acme[3]=x+1;
				if(x<0) acme[3]=0;			
			}
		}
		int min=9999,fag;
		for(i=0;i<4;i++)
			if(acme[i]<min)
			{
				min=acme[i];
				fag=i;
			}
		cout<<min+1<<" "<<Acme[fag]<<endl;		
	}
	return 0;
}
