#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a,b,c,d;
	int i;
	char dd,hh,mm;
	cin>>a>>b>>c>>d;
	for(i=0;i<a.size()&&i<b.size();i++)
	{
		if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G')
		{
			dd=a[i];
			break;
		}
	}
	for(i=i+1;i<a.size()&&i<b.size();i++)
	{
		if((a[i]==b[i])&&((a[i]>='0'&&a[i]<='9')||(a[i]>='A'&&a[i]<='N')))
		{
			hh=a[i];
			break;	
		}	
	}
	for(i=0;i<c.size()&&i<d.size();i++)
	{
		if(c[i]==d[i]&&((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z')))
		{
			mm=i;
			break;	
		}	
	}
	switch(dd)
	{
		case 'A':printf("MON ");break;
		case 'B':printf("TUE ");break;
		case 'C':printf("WED ");break;
		case 'D':printf("THU ");break;
		case 'E':printf("FRI ");break;
		case 'F':printf("SAT ");break;
		case 'G':printf("SUN ");break;
	}
	if(hh>='0'&&hh<='9')
		printf("%02d:",hh-'0');
	else if(hh>='A'&&hh<='N')
		printf("%02d:",hh-'A'+10);
	printf("%02d",mm);
	return 0;	
} 
