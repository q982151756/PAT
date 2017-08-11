#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a[10010];
int cmp(string a,string b)
{
	return a+b<b+a;
}
int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	string s;
	for(i=0;i<n;i++)
		s+=a[i];
	while(s.length()!=0&&s[0]=='0')
		s.erase(s.begin());
	if(s.length()==0)
		cout<<0;
	else
		cout<<s;
	return 0;
}
