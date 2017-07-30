#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<string>
using namespace std;
char b[105];
int main()
{
	int sum=0;
	map<char,string> c;
	c['0']="zero";
	c['1']="one";
	c['2']="two";
	c['3']="three";
	c['4']="four";
	c['5']="five";
	c['6']="six";
	c['7']="seven";
	c['8']="eight";
	c['9']="nine";
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++)
		sum+=n[i]-'0';
	sprintf(b,"%d",sum);
	for(int i=0;i<strlen(b);i++)
	{
		if(i==0) cout<<c[b[i]];
		else cout<<" "<<c[b[i]];
	}
	return 0;
}
