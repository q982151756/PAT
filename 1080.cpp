#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct school
{
	vector<int> students;
	int count;
}; 
struct student
{
	int ge,gi,rank,id,sch;
	double fin;
	vector<int> ap;
};
int cmp(student a,student b)
{
	if(a.fin!=b.fin)
		return a.fin>b.fin;
	else
		return a.ge>b.ge;
}
int main()
{
	int n,m,k,i,j;
	scanf("%d%d%d",&n,&m,&k);
	vector<school> nn(m);
	vector<student> mm(n);
	for(i=0;i<m;i++)
		scanf("%d",&nn[i].count);
	for(i=0;i<n;i++)
	{
		mm[i].id=i;
		scanf("%d%d",&mm[i].ge,&mm[i].gi);
		mm[i].fin=(mm[i].ge+mm[i].gi)/2.0;
		for(j=0;j<k;j++)
		{
			int temp;
			scanf("%d",&temp);
			mm[i].ap.push_back(temp);
		}
	}
	sort(mm.begin(),mm.end(),cmp);
	int ranks=2,temp=1;
	mm[0].rank=1;
	for(i=1;i<n;i++)
	{
		if(mm[i].fin<mm[i-1].fin)
		{
			temp=ranks;
			mm[i].rank=temp;
		}
		else if(mm[i].ge<mm[i-1].ge)
		{
			temp=ranks;
			mm[i].rank=temp;
		}
		else if(mm[i].fin==mm[i-1].fin&&mm[i].ge==mm[i-1].ge)
			mm[i].rank=temp;
		ranks++;
	}
	/*for(i=0;i<n;i++)
	{
		printf("%d %d %d %d",mm[i].id,mm[i].ge,mm[i].gi,mm[i].fin);
		for(j=0;j<mm[i].ap.size();j++)
			printf(" %d",mm[i].ap[j]);
		printf(" %d\n",mm[i].rank);
	}*/
	
	for(j=0;j<k;j++)
	{
		if(nn[mm[0].ap[j]].count>0)
		{
			nn[mm[0].ap[j]].count--;
			nn[mm[0].ap[j]].students.push_back(mm[0].id);
			mm[0].sch=mm[0].ap[j];
			break;
		}
	}
	for(i=1;i<n;i++)
	{
		if(mm[i].rank!=mm[i-1].rank)
		{
			for(j=0;j<k;j++)
			{
				if(nn[mm[i].ap[j]].count>0)
				{
					nn[mm[i].ap[j]].count--;
					nn[mm[i].ap[j]].students.push_back(mm[i].id);
					mm[i].sch=mm[i].ap[j];
					break;
				}
			}
		}
		else
		{
			for(j=0;j<k;j++)
			{
				if(mm[i].ap[j]==mm[i-1].ap[j]&&mm[i-1].sch==mm[i-1].ap[j])
				{
					nn[mm[i].ap[j]].count--;
					nn[mm[i].ap[j]].students.push_back(mm[i].id);
					mm[i].sch=mm[i].ap[j];
					break;
				}
				else
				{
					if(nn[mm[i].ap[j]].count>0)
					{
						nn[mm[i].ap[j]].count--;
						nn[mm[i].ap[j]].students.push_back(mm[i].id);
						mm[i].sch=mm[i].ap[j];
						break;
					}
				}
			}
		}
	}
	for(i=0;i<m;i++)
	{
		sort(nn[i].students.begin(),nn[i].students.end());
		if(nn[i].students.size()>0)
		{
			for(j=0;j<nn[i].students.size();j++)
			{
				if(j==0) printf("%d",nn[i].students[j]);
				else printf(" %d",nn[i].students[j]);
			}
		}	
		printf("\n");
	}
	return 0;
}
