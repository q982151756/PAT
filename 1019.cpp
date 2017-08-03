#include<iostream>
using namespace std;
int main()
{
	int i,j,k;
	long long n,b;
	int a[1000];
	cin>>n>>b;
	if(n==0)
	{
		cout<<"Yes"<<endl;
		cout<<"0";
	}
	else{
		j=0;
	while(n)
	{
		a[j]=n%b;
		n/=b;
		j++;
	}
	int temp=j-1;
	for(i=0,k=temp;i<k;i++,k--)
	{
		if(a[i]!=a[k]) break;
	}
	if(i<k) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	for(i=temp;i>=0;i--)
	{
		if(i==temp) cout<<a[i];
		else cout<<" "<<a[i];
	}
}
	return 0;
}
