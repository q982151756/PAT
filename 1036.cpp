#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef struct student
{
	string name;
	char sex;
	string id;
	int score;
}A;
int cmp(A a,A b)
{
	return a.score>b.score;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	vector<A> F;
	vector<A> M;
	for(i=0;i<n;i++)
	{
		A temp;
		cin>>temp.name>>temp.sex>>temp.id>>temp.score;
		if(temp.sex=='M') M.push_back(temp);
		else if(temp.sex=='F') F.push_back(temp);
	}
	sort(M.begin(),M.end(),cmp);
	sort(F.begin(),F.end(),cmp);
	if(M.size()==0&&F.size()==0)
	{
		printf("Absent\nAbsent\nNA");
	}
	else if(M.size()!=0&&F.size()==0)
	{
		printf("Absent\n");
		cout<<M[M.size()-1].name<<" "<<M[M.size()-1].id<<endl<<"NA";
	}
	else if(M.size()==0&&F.size()!=0)
	{
		cout<<F[0].name<<" "<<F[0].id<<endl;
		printf("Absent\nNA");
	}
	else if(M.size()!=0&&F.size()!=0)
	{
		cout<<F[0].name<<" "<<F[0].id<<endl;
		cout<<M[M.size()-1].name<<" "<<M[M.size()-1].id<<endl;
		cout<<F[0].score-M[M.size()-1].score;
	}
	return 0;
}
