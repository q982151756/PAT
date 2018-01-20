#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n,i,j,ans,max=0;
	scanf("%d",&n);
	int t = sqrt(n);
	for(i=2;i<=t;i++) {
		int count = 0;
		int s = i;
		int temp = n;
		while(temp%s == 0) {
			count++;
			temp = temp/s;
			s++;
		}
		if(count>max) {
			max = count;
			ans = i;
		}
	}
	if(max == 0) {
		printf("1\n%d",n);
		return 0;
	} 
	printf("%d\n%d",max,ans);
	for(i=1;i<max;i++) {
		printf("*%d",ans+i);
	}
	return 0;
} 
