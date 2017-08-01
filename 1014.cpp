#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct node
{
	int poptime;
	int endtime;
	queue<int> q;
};
int main()
{
	int n,m,k,q,i,j,index=1;
	cin>>n>>m>>k>>q;
	vector<node> window(n+1);
	vector<int> time(k+1);
	vector<int> result(k+1);
	vector<bool> sorry(k+1,false);
	for(i=1;i<=k;i++)
		cin>>time[i];
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(index<=k)
			{
				window[j].q.push(time[index]);
				if(window[j].endtime>=540)
					sorry[index]=true;
				window[j].endtime+=time[index];
				if(i==1)
					window[j].poptime=window[j].endtime;
				result[index]=window[j].endtime;
			}
			index++;
			
		}
	}
	while(index<=k)
	{
		int tempmin=window[1].poptime,tempwindow=1;
		for(i=2;i<=n;i++)
		{
			if(window[i].poptime<tempmin)
			{
				tempmin=window[i].poptime;
				tempwindow=i;
			}
		}
		window[tempwindow].q.pop();
		window[tempwindow].q.push(time[index]);
		window[tempwindow].poptime+=window[tempwindow].q.front();
		if(window[tempwindow].endtime>=540)
			sorry[index]=true;
		window[tempwindow].endtime+=time[index];
		result[index]=window[tempwindow].endtime;
		index++;
	}
	for(int i = 1; i <= q; i++) {
        int query, minute;
        scanf("%d", &query);
        minute = result[query];
        if(sorry[query] == true) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n",(minute + 480) / 60, (minute + 480) % 60);
        }
    }
    return 0;
}
