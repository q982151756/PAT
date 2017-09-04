#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	int i;
	string s1,s2;
	map<char,int> mm;
	getline(cin,s1);
	getline(cin,s2);
	for(i=0;i<s2.size();i++)
	{
		mm[s2[i]]=1;
	}
	for(i=0;i<s1.size();i++)
	{
		if(mm[s1[i]]!=1) cout<<s1[i];
	}
}

