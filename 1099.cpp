#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
struct node {
	int data;
	int left;
	int right;
};
vector<node> mm;
vector<int> in,past,level;
void inorder(int r) {
	if(mm[r].left!=-1) {
		inorder(mm[r].left);	
	}
	in.push_back(r);
	if(mm[r].right!=-1) {
		inorder(mm[r].right);
	}
}
void levelq(int r) {
	queue<int> q;
	q.push(r);
	while(!q.empty()) {
		int temp=q.front();
		level.push_back(temp);
		q.pop();
		if(mm[temp].left!=-1) q.push(mm[temp].left);
		if(mm[temp].right!=-1) q.push(mm[temp].right);	
	}
}
int main() {
	int n,i,j;
	map<int,int> tmap;
	scanf("%d",&n);
	mm.resize(n);
	past.resize(n);
	for(i=0;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		mm[i].left=a;
		mm[i].right=b;
	}
	for(i=0;i<n;i++) {
		scanf("%d",&past[i]);
	}
	sort(past.begin(),past.end());
	inorder(0);
	for(i=0;i<n;i++) {
		tmap[in[i]]=past[i];
	}
	levelq(0);
	printf("%d",tmap[level[0]]);
	for(i=1;i<n;i++) {
		printf(" %d",tmap[level[i]]);
	}
	return 0;
}
 
