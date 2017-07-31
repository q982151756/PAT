#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
char n1[20],n2[20];
int tag,radix;
long long map[256];
long long convertToTen(char a[],long long radix)
{
	long long ans=0;
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		ans=ans*radix+map[a[i]];
	}
	return ans;
}
int findLargestDigit(char n2[])
{
	int ans=-1,len=strlen(n2);
	for(int i=0;i<len;i++)
	{
		if(map[n2[i]]>ans)
			ans=map[n2[i]];
	}
	return ans+1;
}
int cmp(char n2[],long long radix,long long t)
{
	int len=strlen(n2);
	long long num=convertToTen(n2,radix);
	if(num < 0) return 1;//考虑溢出，溢出后返回负数 
    	if(num < t) return -1;
    	return (t == num) ? 0 : 1;
}
long long bs(char n2[],long long left,long long right,long long t)
{
	long long mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		int flag=cmp(n2,mid,t);
		if(flag==0) return mid;
		if(flag==-1) left=mid+1;
		if(flag==1) right=mid-1;
	}
	return -1;
}
int main()
{
	cin>>n1>>n2>>tag>>radix;
	for(char c='0';c<='9';c++)
	{
		map[c]=c-'0';
	}
	for(char c='a';c<='z';c++)
	{
		map[c]=c-'a'+10;
	}
	if(tag==2) swap(n1,n2);
	long long t=convertToTen(n1,radix);
	long long low=findLargestDigit(n2);
	long long high=max(t,low);
	long long ans=bs(n2,low,high,t);
	if(ans==-1) printf("Impossible");
	else printf("%lld",ans);
	return 0;
}

