#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	long n,i,j;
	vector<long> a;
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
		long temp;
		scanf("%ld",&temp);
		a.push_back(temp);
	}
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
		long temp;
		scanf("%ld",&temp);
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	j=0;
	for(i=1;i<a.size();i++)
	{
		if(a[i]==a[j]) continue;
		else swap(a[j+1],a[i]);
		j++;	
	}
	int temp=j/2;
	printf("%ld",a[temp]);
	return 0;
}
