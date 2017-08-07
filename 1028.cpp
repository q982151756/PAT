#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100001;
struct student
{
	long long id;
	char name[10];
	int grade;
}a[maxn];
int c;
int cmp1(struct student a,struct student b)
{
    if(c == 1)
        return a.id < b.id;
    else if(c == 2)
        return strcmp(a.name, b.name) <= 0;
    else
        return a.grade <= b.grade;
}	
int main()
{
	int n,i;
	scanf("%d %d",&n,&c);
	for(i=0;i<n;i++)
		scanf("%d %s %d",&a[i].id,a[i].name,&a[i].grade);
	sort(a,a+n,cmp1);
	for(i=0;i<n;i++)
	{
		printf("%06d %s %d\n", a[i].id, a[i].name, a[i].grade);
    }
    return 0;
}
