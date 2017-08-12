#include<iostream>
using namespace std;
int a[100010],b[10100];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	for(i=0;i<n;i++)
	{
		if(b[a[i]]==1)
		{
			printf("%d",a[i]);
			break;
		}
	}
	if(i==n) printf("None");
	return 0;
} 
