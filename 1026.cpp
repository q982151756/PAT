#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct people
{
	int arrivetime,playtime,servetime,vipflag;
	float waittime;
}A;
int cmp(A a,A b)
{
	return a.arrivetime<b.arrivetime;
}
int viptable[105],num[4];
int main()
{
	int n,i,j,k,m;
	cin>>n;
	vector<A> a(n);
	for(i=0;i<n;i++)
	{
		int hh,mm,ss,time;
		scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&a[i].playtime,&a[i].vipflag);
		if(a[i].playtime>=120) a[i].playtime=120;
		a[i].playtime*=60;
		time=hh*3600+mm*60+ss;
		a[i].arrivetime=time;
	}
	cin>>k>>m;
	for(i=0;i<m;i++)
	{
		int temp;
		cin>>temp;
		viptable[temp]=1;
	}
	queue<A> ordinary,vip,pp;
	vector<int> table(k+1,28800);
	sort(a.begin(),a.end(),cmp);
	for(i=0;i<a.size();i++)
		pp.push(a[i]);
	while(true)
	{
		int index,mintable=999999999;
		for(i=1;i<=k;i++)
		{
			if(table[i]<mintable)
			{
				index=i;
				mintable=table[i];
			}
		}
		//cout<<index<<endl;
		if(table[index]>=75600) break;
		while(pp.empty()==false&&pp.front().arrivetime<table[index])
		{
			if(pp.front().vipflag==0)
			{
				ordinary.push(pp.front());
				pp.pop();
			}
			else if(pp.front().vipflag==1)
			{
				vip.push(pp.front());
				pp.pop();
			}
		}
		if(ordinary.empty()==true&&vip.empty()==true)
		{
			table[index]=pp.front().arrivetime+pp.front().playtime;
			pp.front().servetime=pp.front().arrivetime;
			pp.front().waittime=0;
			int hh1,mm1,ss1;
			hh1=pp.front().arrivetime/3600;
			pp.front().arrivetime%=3600;
			mm1=pp.front().arrivetime/60;
			ss1=pp.front().arrivetime%60;
			printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",hh1,mm1,ss1,hh1,mm1,ss1,pp.front().waittime);
			pp.pop();
			num[index]++;	
		}
		else if(viptable[index]==1)
		{
			if(vip.empty()==false)
			{
				int temp=table[index];
				vip.front().waittime=(table[index]-vip.front().arrivetime)/60.0+0.1;
				//cout<<vip.front().arrivetime<<" "<<table[index]<<endl;
				//cout<<endl;
				int h1,m1,s1,h2,m2,s2;
				h1=vip.front().arrivetime/3600;
				vip.front().arrivetime%=3600;
				m1=vip.front().arrivetime/60;
				s1=vip.front().arrivetime%60;
				h2=temp/3600;
				temp%=3600;
				m2=temp/60;
				s2=temp%60;
				printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",h1,m1,s1,h2,m2,s2,vip.front().waittime);
				table[index]+=vip.front().playtime;
				vip.pop();
				num[index]++;
			}
			else
			{
				int temp=table[index];
				ordinary.front().waittime=(table[index]-ordinary.front().arrivetime)/60.0+0.1;
				//cout<<vip.front().arrivetime<<" "<<table[index]<<endl;
				//cout<<endl;
				int h1,m1,s1,h2,m2,s2;
				h1=ordinary.front().arrivetime/3600;
				ordinary.front().arrivetime%=3600;
				m1=ordinary.front().arrivetime/60;
				s1=ordinary.front().arrivetime%60;
				h2=temp/3600;
				temp%=3600;
				m2=temp/60;
				s2=temp%60;
				printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",h1,m1,s1,h2,m2,s2,ordinary.front().waittime);
				table[index]+=ordinary.front().playtime;
				ordinary.pop();
				num[index]++;
			}
		}
		else if(viptable[index]==0)
		{
			if(vip.empty()==true)
			{
				int temp=table[index];
				ordinary.front().waittime=(table[index]-ordinary.front().arrivetime)/60.0+0.1;
				//cout<<vip.front().arrivetime<<" "<<table[index]<<endl;
				//cout<<endl;
				int h1,m1,s1,h2,m2,s2;
				h1=ordinary.front().arrivetime/3600;
				ordinary.front().arrivetime%=3600;
				m1=ordinary.front().arrivetime/60;
				s1=ordinary.front().arrivetime%60;
				h2=temp/3600;
				temp%=3600;
				m2=temp/60;
				s2=temp%60;
				printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",h1,m1,s1,h2,m2,s2,ordinary.front().waittime);
				table[index]+=ordinary.front().playtime;
				ordinary.pop();
				num[index]++;
			}
			else if(ordinary.empty()==true)
			{
				int temp=table[index];
				vip.front().waittime=(table[index]-vip.front().arrivetime)/60.0+0.1;
				//cout<<vip.front().arrivetime<<" "<<table[index]<<endl;
				//cout<<endl;
				int h1,m1,s1,h2,m2,s2;
				h1=vip.front().arrivetime/3600;
				vip.front().arrivetime%=3600;
				m1=vip.front().arrivetime/60;
				s1=vip.front().arrivetime%60;
				h2=temp/3600;
				temp%=3600;
				m2=temp/60;
				s2=temp%60;
				printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",h1,m1,s1,h2,m2,s2,vip.front().waittime);
				table[index]+=vip.front().playtime;
				vip.pop();
				num[index]++;
			}
			else if(ordinary.front().arrivetime<vip.front().arrivetime)
			{
				int temp=table[index];
				ordinary.front().waittime=(table[index]-ordinary.front().arrivetime)/60.0+0.1;
				//cout<<vip.front().arrivetime<<" "<<table[index]<<endl;
				//cout<<endl;
				int h1,m1,s1,h2,m2,s2;
				h1=ordinary.front().arrivetime/3600;
				ordinary.front().arrivetime%=3600;
				m1=ordinary.front().arrivetime/60;
				s1=ordinary.front().arrivetime%60;
				h2=temp/3600;
				temp%=3600;
				m2=temp/60;
				s2=temp%60;
				printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",h1,m1,s1,h2,m2,s2,ordinary.front().waittime);
				table[index]+=ordinary.front().playtime;
				ordinary.pop();
				num[index]++;
			}
			else
			{
				int temp=table[index];
				vip.front().waittime=(table[index]-vip.front().arrivetime)/60.0+0.1;
				//cout<<vip.front().arrivetime<<" "<<table[index]<<endl;
				//cout<<endl;
				int h1,m1,s1,h2,m2,s2;
				h1=vip.front().arrivetime/3600;
				vip.front().arrivetime%=3600;
				m1=vip.front().arrivetime/60;
				s1=vip.front().arrivetime%60;
				h2=temp/3600;
				temp%=3600;
				m2=temp/60;
				s2=temp%60;
				printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",h1,m1,s1,h2,m2,s2,vip.front().waittime);
				table[index]+=vip.front().playtime;
				vip.pop();
				num[index]++;
			}
		}
		if(pp.empty()==true&&ordinary.empty()==true&&vip.empty()==true)
			break;	
	}
	for(i=1;i<=k;i++)
	{
		if(i==1) cout<<num[i];
		else cout<<" "<<num[i];
	}
	return 0;
}
