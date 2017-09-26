#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	int i,count=0,max1=0;
	map<string,int> mm;
	string a,ans,t;
	getline(cin,a);
	for(i=0;i<a.size();i++)
	{
		if((a[i]>='0'&&a[i]<='9')||(a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
		{
			if(a[i]>='A'&&a[i]<='Z')
				a[i]+=32;
			t+=a[i];
		}
		else if(t!="")
		{
			mm[t]++;
			if(mm[t]>max1)
			{
				max1=mm[t];
				ans=t;
			}
			t="";
		}
		//cout<<t<<endl;
	}
	mm[t]++;
	if(mm[t]>max1)
	{
		max1=mm[t];
		ans=t;
	}
	cout<<ans+" "<<max1;
	return 0;
}
