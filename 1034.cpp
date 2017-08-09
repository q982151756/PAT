#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> sti;
map<int,string> its;
map<string,int> ans;
int k,idnumber=1;
int weight[2005],G[2005][2005];
bool book[2005];
int one(string s)
{
	if(sti[s]==0)
	{
		sti[s]=idnumber;
		its[idnumber]=s;
		return idnumber++;
	}
	else
		return sti[s];
}
void dfs(int u,int &head,int &number,int &totalweight)
{
	book[u]=true;
	number++;
	if(weight[u]>weight[head]) head=u;
	for(int v=1;v<idnumber;v++)
	{
		if(G[u][v]>0)
		{
			totalweight+=G[u][v];
			G[u][v]=G[v][u]=0;
			if(book[v]==false)
				dfs(v,head,number,totalweight);
		}
	}
}
void dfs1()
{
	for(int i=0;i<idnumber;i++)
	{
		if(book[i]==false)
		{
			int head=i,number=0,totalweight=0;
			dfs(i,head,number,totalweight);
			if(number>2&&totalweight>k)
				ans[its[head]]=number;
		}
	}
}
int main()
{
	int n,w;
	cin>>n>>k;
	string s1,s2;
	for(int i=0;i<n;i++)
	{
		cin>>s1>>s2>>w;
		int id1=one(s1);
		int id2=one(s2);
		weight[id1]+=w;
		weight[id2]+=w;
		G[id1][id2]+=w;
		G[id2][id1]+=w;
	}
	dfs1();
	cout<<ans.size()<<endl;
	for(auto it=ans.begin();it!=ans.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
	return 0;
} 

