#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
	string a;
	int i,j,n1,n2,N;
	cin>>a;
	N=a.size();
	for(i=1;;i++)
	{
		if(N+2-i*2<i) break; 
		else n1=i;
	}
	n2=N+2-n1*2;
	vector<vector<char> > p(n1,vector<char>(n2));
	int left=0,right=a.size()-1;
	for(i=0;i<n1;i++)
	{
		if(i!=n1-1)
		{
			for(j=0;j<n2;j++)
			{
				if(j==0) {p[i][j]=a[left];left++;}
				else if(j==n2-1) {p[i][j]=a[right];right--;}
				else p[i][j]=' ';
			}
		}
		else
		{
			for(j=0;j<n2;j++)
			{
				p[i][j]=a[left];
				left++;
			}
		}	
	}
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
			printf("%c",p[i][j]);
		printf("\n");
	}
	return 0;
}
