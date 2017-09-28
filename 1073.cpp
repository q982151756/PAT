#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i;
	string a,ans,b;
	char flag;
	cin>>a;
	b=a;
	for(i=1;i<a.size();i++)
	{
		if(a[i]=='.') continue;
		if(a[i]=='E') break;
		ans+=a[i];
	}
	cout<<ans<<endl;
	flag=a[i+1];
	int num=stoi(b.substr(i+2));
	int front=0,back=0;
	for(i=1;i<a.size();i++)
	{
		if(a[i]=='.') break;
		front++;
	}
	for(i+=1;i<a.size();i++)
	{
		if(a[i]=='E') break;
		back++;
	}
	if(a[0]=='-') printf("%c",a[0]);
	if(flag=='+')
	{
		if(num>=back)
		{
			cout<<ans;
			for(i=0;i<num-back;i++)
				printf("0");
		}
		else
		{
			for(i=0;i<ans.size();i++)
			{
				if(i==front+num) printf(".");
				printf("%c",ans[i]);
			}
		}
	}
	else if(flag=='-')
	{
		if(num>=front)
		{
			printf("0.");
			for(i=0;i<num-front;i++)
				printf("0");
			cout<<ans;
		}
		else
		{
			for(i=0;i<ans.size();i++)
			{
				if(i==front-num) printf(".");
				printf("%c",ans[i]);
			}
		}
	}
	return 0;
}
