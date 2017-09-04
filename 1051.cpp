#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int n,m,k,i,j,x,flag,max=0;
	scanf("%d%d%d",&n,&m,&k);
	vector<int> temp(m);
	while(k--)
	{
		stack<int> a;
		a.push(1);
		flag=1;max=0;
		for(i=0;i<m;i++)
			scanf("%d",&temp[i]);
		for(i=0;i<m;i++)
		{
			if(max<flag) max=flag;
			int s=a.size();
			for(j=max+1,x=0;j<=temp[i]&&x<n-s;j++,x++)
			{
				a.push(j);
			}
			flag=a.top();
			if(a.top()!=temp[i]) break;
			else
			{
				a.pop();
			}
		}
		if(i<m) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
