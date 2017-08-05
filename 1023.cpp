#include<iostream>
#include<cstring>
using namespace std;
char a[50];
int b[50],re[50];
int book[10];
int main()
{
	int i,j,flag=0;
	scanf("%s",a);
	for(i=0;i<strlen(a);i++)
	{
		b[i]=a[i]-'0';
		book[b[i]]++;
	}
	for(i=strlen(a)-1;i>=0;i--)
	{
		b[i]*=2;
		if(flag==1) b[i]+=1;
		flag=0;
		if(b[i]>=10&&i>=1)
		{
			b[i]-=10;
			flag=1;
		}
	}
	//for(i=0;i<strlen(a);i++)
		//cout<<b[i]<<" ";
	int temp=0;
	if(b[0]>=10)
	{
		b[0]-=10;
		temp+=1;	
	}
	if(temp>0) book[temp]--;
	for(i=0;i<strlen(a);i++)
		book[b[i]]--;
	for(i=0;i<10;i++)
		if(book[i]>0) break;
	if(i==10) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	if(temp>0) cout<<temp;
	for(i=0;i<strlen(a);i++)
		cout<<b[i];
	return 0;	
}
