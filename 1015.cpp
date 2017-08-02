#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	long n,d,i,j,k;
	while(true)
	{
		cin>>n;
		if(n<0) break;
		cin>>d;
		for(i=2;i<=sqrt(n);i++)
			if(n%i==0) break;
		if(i<=sqrt(n)||n==0||n==1) cout<<"No"<<endl;
		else
		{
			long t[1000],sum=0;j=0;
			while(n)
			{
				t[j]=n%d;
				n/=d;
				j++;
			}
			for(i=0;i<j;i++)
				sum=sum*d+t[i];
			for(k=2;k<=sqrt(sum);k++)
				if(sum%k==0) break;
			if(k<=sqrt(sum)||sum==0||sum==1) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}
	return 0;
}
