#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;
int main()
{
	map<string,set<string>> book;
	int n,m,i,j;
	cin>>n;
	getchar();
	for(i=0;i<n;i++)
	{
		string id,title,autor,publisher,year,key;
		getline(cin,id);
		getline(cin,title);
		getline(cin,autor);
		getline(cin,key);
		getline(cin,publisher);
		getline(cin,year);
		book[title].insert(id);
		book[autor].insert(id);
		int fag=0;
		for(j=0;j<key.size();j++)
		{
			if(key[j]==' ')
			{
				string temp;
				for(int k=fag;k<j;k++)
					temp+=key[k];
				//cout<<temp<<endl;
				book[temp].insert(id);
				fag=j+1;
			}
		}
		string temp;
		for(int k=fag;k<key.size();k++)
			temp+=key[k];
		//cout<<temp<<endl;
		book[temp].insert(id);
		book[publisher].insert(id);
		book[year].insert(id);	
	}
	//cout<<book["The Testing Book"].size()<<endl;
	cin>>m;
	for(i=0;i<m;i++)
	{
		int flag;
		string t;
		scanf("%d: ",&flag);
		getline(cin,t);
		printf("%d: ",flag);
		for(j=0;j<t.size();j++)
			cout<<t[j];
		cout<<endl;
		if(book[t].size()==0) cout<<"Not Found"<<endl;
		else
		{
			for(auto it=book[t].begin();it!=book[t].end();it++)
			{
				cout<<*it<<endl;
			}
		}
	}
	return 0;
}
