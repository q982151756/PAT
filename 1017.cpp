#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	int come,time;
};
int cmp(node a,node b)
{
	return a.come<b.come;
}
int main()
{
	int n,k,i,j;
	double re=0;
	cin>>n>>k;
	vector<node> custom;
	for(i=0;i<n;i++)
	{
		node t;
		int hh,mm,ss,tt,temp=0;
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&tt);
		temp=hh*3600+mm*60+ss;
		if(temp>61200) continue;
		t.come=temp;
		if(tt>60) tt=60;
		t.time=tt*60;
		custom.push_back(t);
	}
	sort(custom.begin(),custom.end(),cmp);
	vector<int> window(k,28800);
	for(i=0;i<custom.size();i++)
	{
		int tempindex=0,tempwindow=window[0];
		for(j=1;j<k;j++)
		{
			if(window[j]<tempwindow)
			{
				tempwindow=window[j];
				tempindex=j;
			}
		}
		if(custom[i].come>=window[tempindex]) 
		{
			window[tempindex]=custom[i].come+custom[i].time;
		}
		else
		{
			re=re+window[tempindex]-custom[i].come;
			window[tempindex]+=custom[i].time;
		}
	}
	if(custom.size()==0) printf("0.0");
	else
		printf("%.1f",re/60.0/custom.size());
	return 0;	
}
