#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	int address;
	int key;
	int next;
	bool flag;
}map[100001];
int cmp(node x,node y)
{
	if(x.flag==false||y.flag==false)
		return x.flag>y.flag;
	else
		return x.key<y.key;
}
int main()
{
	int n,first,i,j,cnt=0;
	scanf("%d%d",&n,&first);
	for(i=0;i<n;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		map[x].address=x;map[x].key=y;map[x].next=z;
	}
	for(i=first;i!=-1;i=map[i].next)
	{
		map[i].flag=true;
		cnt++;
	}
	if(cnt==0) printf("0 -1");
	else
	{
		sort(map,map+100001,cmp);
		printf("%d %d\n",cnt,map[0].address);
		for(i=0;i<cnt;i++)
		{
			if(i!=cnt-1)
				printf("%05d %d %05d\n",map[i].address,map[i].key,map[i+1].address);
			else
				printf("%05d %d -1",map[i].address,map[i].key);
		}
	}
	return 0;
}
