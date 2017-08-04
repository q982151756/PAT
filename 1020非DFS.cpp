#include<iostream>
#include<vector>
using namespace std;
int post[35],in[35];
vector<int> level(100000,-1);
void pre(int root,int start,int end,int index)
{
	if(start>end) return;
	int i=start;
	while(i<end&&in[i]!=post[root]) i++;
	level[index]=post[root];
	pre(root-1-end+i,start,i-1,2*index+1);
	pre(root-1,i+1,end,2*index+2);
}
int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>post[i];
	for(i=0;i<n;i++)
		cin>>in[i];
	pre(n-1,0,n-1,0);
	int cnt=0;
	for(i=0;i<level.size();i++)
	{
		if(level[i]!=-1&&cnt==0)
		{
			cout<<level[i];
			cnt++;
		}
		else if(level[i]!=-1)
		{
			cout<<" "<<level[i];
			cnt++;
		}
	}
	return 0;
}
