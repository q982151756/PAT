#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef struct node
{
	string name;
	string p;
}A;
int main()
{
	int n,i,j;
	cin>>n;
	vector<A> a(n);
	vector<A> ans;
	for(i=0;i<n;i++)
	{
		int flag=0;
		cin>>a[i].name>>a[i].p;
		for(j=0;j<a[i].p.size();j++)
		{
			if(a[i].p[j]=='1')
			{
				a[i].p[j]='@';
				flag=1;
			}
			else if(a[i].p[j]=='0')
			{
				a[i].p[j]='%';
				flag=1;
			}
			else if(a[i].p[j]=='l')
			{
				a[i].p[j]='L';
				flag=1;
			}
			else if(a[i].p[j]=='O')
			{
				a[i].p[j]='o';
				flag=1;
			}
		}
		if(flag==1)
			ans.push_back(a[i]);
	}
	if(ans.size()>0)
	{
		cout<<ans.size()<<endl;
		for(i=0;i<ans.size();i++)
			cout<<ans[i].name<<" "<<ans[i].p<<endl;
	}
	else if(ans.size()==0)
	{
		if(n==1)
			cout<<"There is 1 account and no account is modified"<<endl;
		else if(n>1)
			printf("There are %d accounts and no account is modified\n",n);
	}	
	return 0;
}
