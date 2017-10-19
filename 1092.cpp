#include<iostream>
using namespace std;
int a[150];
int main()
{
	int ans1=0,ans2=0,flag=0,i;
	char temp;
	scanf("%c",&temp);
	while(temp!='\n')
	{
		a[(int)temp]++;
		scanf("%c",&temp);
	}
	scanf("%c",&temp);
	while(temp!='\n')
	{
		if(a[(int)temp]>0)
			a[(int)temp]--;
		else
		{
			flag=1;
			ans2++;
		}
		scanf("%c",&temp);
	}
	for(i=0;i<150;i++)
	{
		if(a[i]>0)
			ans1+=a[i];
	}
	if(flag==1)
	{
		printf("No %d\n",ans2);
	}
	else printf("Yes %d\n",ans1);
	return 0;
} 
