#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct student
{
	string name,id;
	int grade;
};
int cmp(student a,student b)
{
	return a.grade>b.grade;
}
int main()
{
	int n,i,grade1,grade2,j;
	scanf("%d",&n);
	vector<student> a(n);
	for(i=0;i<n;i++)
	{
		cin>>a[i].name>>a[i].id>>a[i].grade;
	}
	scanf("%d%d",&grade1,&grade2);
	sort(a.begin(),a.end(),cmp);
	for(i=0;i<n;i++)
		if(a[i].grade<=grade2)
			break;
	if(i==n) printf("NONE");
	else
	{
		for(j=i;j<n;j++)
			if(a[j].grade<grade1)
				break;
		if(j==i) printf("NONE");
		for(int k=i;k<j;k++)
		{
			cout<<a[k].name<<" "<<a[k].id<<endl;
		}
	}
	return 0;	
} 
