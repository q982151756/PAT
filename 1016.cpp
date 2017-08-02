#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
	string name;
	int status,time,month,day,hour,minute;
};
int cmp(struct node a,struct node b)
{
	return a.name!=b.name?a.name<b.name:a.time<b.time;
}
double billfromzero(node call,int *rate)
{
	double totle=rate[call.hour]*call.minute+rate[24]*60*call.day;
	for(int i=0;i<call.hour;i++)
	{
		totle+=rate[i]*60;
	}
	return totle/100.0;
}
int main()
{
	int i,j,n;
	int rate[25]={0};
	for(i=0;i<24;i++)
	{
		scanf("%d",&rate[i]);
		rate[24]+=rate[i];	
	}
	cin>>n;
	vector<node> record(n);
	for(i=0;i<n;i++)
	{
		cin>>record[i].name;
		scanf("%d:%d:%d:%d",&record[i].month,&record[i].day,&record[i].hour,&record[i].minute);
		record[i].time=record[i].day*24*60+record[i].hour*60+record[i].minute;
		string temp;
		cin>>temp;
		record[i].status=(temp=="on-line"?1:0);	
	}
	sort(record.begin(),record.end(),cmp);
	map<string,vector<node> > custom;
	for(i=1;i<record.size();i++)
	{
		if(record[i].name==record[i-1].name&&record[i].status==0&&record[i-1].status==1)
		{
			custom[record[i-1].name].push_back(record[i-1]);
			custom[record[i].name].push_back(record[i]);
		}		
	}
	for(auto it : custom)
	{
		vector<node> temp=it.second;
		double totle=0.0;
		cout<<it.first;
		printf(" %02d\n",temp[0].month);
		for(i=1;i<temp.size();i+=2)
		{
			double t=billfromzero(temp[i],rate)-billfromzero(temp[i-1],rate);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
			totle+=t;
		}
		printf("Total amount: $%.2f\n",totle);
	}
	return 0;	
} 
