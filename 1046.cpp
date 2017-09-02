#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,i,j,m,x,y;
	cin>>n;
	vector<int> a(n+1),b(n+1);
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1) b[i]=0;
		else b[i]=b[i-1]+a[i-1];
	}
	cin>>m;
	for(i=0;i<m;i++)
	{
		int sum1=0,sum2=0,s,e;
		cin>>x>>y;
		s=max(x,y);e=min(x,y);
		sum1=b[s]-b[e];
		sum2=b[n]-b[s]+a[n]+b[e]-b[1];
		cout<<min(sum1,sum2)<<endl;
	}
	return 0;
}
