#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i,j;
	string a,b,ans;
	cin>>a>>b;
	for(i=0;i<a.size();i++)
	{
		if(a[i]>='a'&&a[i]<='z')
			a[i]-=32;
	}
	for(i=0;i<b.size();i++)
	{
		if(b[i]>='a'&&a[i]<='z')
			b[i]-=32;
	}
	for(i=0;i<a.size();i++)
	{
		if(b.find(a[i])==b.npos&&ans.find(a[i])==ans.npos)
			ans+=a[i];
	}
	cout<<ans;
	return 0;
}
