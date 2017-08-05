#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main()
{
	string a,b;
	int n,i,j,k=0;
	cin>>a>>n;
	for(i=1;i<=n+1;i++)
	{
		k=0;
		b.clear();
		for(j=a.size()-1;j>=0;j--)
			b+=a[j];
		//cout<<b<<endl;
		if(a==b) 
		{
			cout<<b<<endl<<i-1<<endl;
			break;
		}
		else
		{
			for(j=a.size()-1;j>=0;j--)
			{
				int temp=a[j]-'0';
				temp+=b[j]-'0';
				temp+=k;
				k=0;
				if(temp>=10)
				{
					temp-=10;
					k=1;
				}
				a[j]=temp+'0';		
			}
			if(k==1)
				a="1"+a;
			//cout<<a<<endl;
		}
	}
	if(i>n+1)
	{
		a.clear();
		for(i=b.size()-1;i>=0;i--)
			a+=b[i];
		cout<<a<<endl<<n<<endl;
	}
	return 0;	
}
