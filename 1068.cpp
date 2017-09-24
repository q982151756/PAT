#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dp[10010][110],visit[10010][110];
int a[10010];
vector<int> ans;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=0;i<=n;i++)
		dp[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j<=m;j++)
		{
			if(dp[i-1][j-a[i]])
			{
				dp[i][j]=1;
				visit[i][j]=1;
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	if(!dp[n][m]) printf("No Solution");
	else
	{
		while(n>0)
		{
			if(visit[n][m])
			{
				ans.push_back(a[n]);
				m-=a[n];
				n--;
			}
			else
				n--;
		}
		for(int i=0;i<ans.size()-1;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("%d",ans[ans.size()-1]);
	}
	return 0;
}
