#include<iostream>
#include<string>
using namespace std;
int dp[1010][1010]; 
int main()
{
	string a;
	int i,j;
	getline(cin,a);
	int len=a.size(),ans=1;
	for(i=0;i<len;i++)
	{
		dp[i][i]=1;
		if(i<len-1&&a[i]==a[i+1])
		{
			dp[i][i+1]=1;
			ans=2;
		}
	}
	for(int L=3;L<=len;L++)
	{
		for(i=0;i+L-1<len;i++)
		{
			j=i+L-1;
			if(a[i]==a[j]&&dp[i+1][j-1]==1)
			{
				dp[i][j]=1;
				ans=L;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
