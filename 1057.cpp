#include<iostream>
#include<stack>
using namespace std;
#define lowbit(i) ((i)&(-i))
const int maxn=100010;
stack<int> s;
int c[maxn];
void update(int x,int v)
{
	for(int i=x;i<maxn;i+=lowbit(i))
		c[i]+=v;
}
int getsum(int x)
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
		sum+=c[i];
	return sum;
}
void peekmedian()
{
	int l=1,r=maxn,mid,k=(s.size()+1)/2;
	while(l<r)
	{
		mid=(l+r)/2;
		if(getsum(mid)>=k) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}
int main()
{
	int n,x;
	char str[15];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		if(str[1]=='u')
		{
			scanf("%d",&x);
			s.push(x);
			update(x,1);
		}
		else if(str[1]=='o')
		{
			if(s.empty()) printf("Invalid\n");
			else
			{
				printf("%d\n",s.top());
				update(s.top(),-1);
				s.pop();
			}
		}
		else
		{
			if(s.empty()) printf("Invalid\n");
			else peekmedian();
		}
	}
	return 0;
}
