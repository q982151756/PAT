#include<iostream>
using namespace std;
int main()
{
	int a[3],i;
	for(i=0;i<3;i++)
		cin>>a[i];
	printf("#");
	for(i=0;i<3;i++)
	{
		int s,t;
		char ss,tt;
		s=a[i]%13;
		a[i]/=13;
		t=a[i]%13;
		if(s>=10)
		{
			s-=10;
			ss=s+'A';
		}
		else
			ss=s+'0';
		if(t>=10)
		{
			t-=10;
			tt=t+'A';
		}
		else
			tt=t+'0';
		cout<<tt<<ss;	
	}
}
