#include<iostream>
using namespace std;
int main()
{
	int n,i,j=0,a,t;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(i==0)
			j+=a*6+5;
		else
		{
			if(a-t>0) j+=(a-t)*6+5;
			else j+=(t-a)*4+5;
		}
		t=a;	
	}
	cout<<j<<endl;
	return 0;
}
