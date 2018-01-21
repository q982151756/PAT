#include<iostream>
#include<vector>
using namespace std;
struct Node {
	int ad;
	int data;
	int next;
};
Node node[100010];
int book[10010];
int main() {
	int first,n,i,j;
	vector<Node> ans1,ans2;
	scanf("%d%d",&first,&n);
	for(i=0;i<n;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		node[a].ad=a;
		node[a].data=b;
		node[a].next=c;
	}
	int t=first;
	while(t!=-1) {
		int temp=(node[t].data<0?-node[t].data:node[t].data);
		if(book[temp]==0) {
			ans1.push_back(node[t]);
			book[temp]=1;
		} 
		else {
			ans2.push_back(node[t]);
		}
		t=node[t].next;
	}
	for(i=0;i<ans1.size();i++) {
		if(i!=ans1.size()-1)
			printf("%05d %d %05d\n",ans1[i].ad,ans1[i].data,ans1[i+1].ad);
		else 
			printf("%05d %d -1\n",ans1[i].ad,ans1[i].data);
	}
	for(i=0;i<ans2.size();i++) {
		if(i!=ans2.size()-1)
			printf("%05d %d %05d\n",ans2[i].ad,ans2[i].data,ans2[i+1].ad);
		else 
			printf("%05d %d -1\n",ans2[i].ad,ans2[i].data);
	}
	return 0;
}
