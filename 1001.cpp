#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char x[20],y[22];
int main() 
{
	int i,j=0,fag=0;
	long long a,b,sum;
	cin>>a>>b;
	sum=a+b;
	if(sum<0) 
	{
		printf("-");
		sum=-sum;
	}
	sprintf(x,"%d",sum);
	for(i=strlen(x)-1;i>=0;i--)
	{
		if(fag%3==0&&fag>0)
		{
			y[j]=',';
			j++;
		}
		y[j]=x[i];
		j++;
		fag++;
	}
	for(i=strlen(y)-1;i>=0;i--)
		printf("%c",y[i]);
	return 0;
}
