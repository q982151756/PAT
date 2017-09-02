#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int stringtoint(char *s)
{
	int temp=0;
	for(int i=0;i<3;i++)
		temp=temp*26+(s[i]-'A');
	return temp*10+(s[3]-'0');
}
void inttostring(int x,char *y)
{
	y[3]=x%10+'0';
	x/=10;
	for(int i=2;i>=0;i--)
	{
		y[i]=x%26+'A';
		x/=26;
	}
}
int main()
{
	int n,m,i,j,temp;
	char x[4],y[4];
	scanf("%d%d",&n,&m);
	vector<int> re[m+1];
	for(i=0;i<n;i++)
	{
		int t,id;
		scanf("%s",x);
		id=stringtoint(x);
		scanf("%d",&temp);
		for(j=0;j<temp;j++)
		{
			scanf("%d",&t);
			re[t].push_back(id);
		}
		
	}
	for(i=1;i<=m;i++)
	{
		printf("%d %d\n",i,re[i].size());
		sort(re[i].begin(),re[i].end());
		for(j=0;j<re[i].size();j++)
		{
			inttostring(re[i][j],y);
			printf("%s\n",y);
		}
	}
	return 0;
} 
