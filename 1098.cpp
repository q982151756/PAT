#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[101],b[101];
int main() {
	int n,i,j;
	int flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++) {
		scanf("%d",&b[i]);
	}
	for(i=1;i<n;i++) {
		if(b[i]<b[i-1]) break;
	}
	int in=i;
	while(i<n && a[i]==b[i]) i++;
	if(i==n) flag=1;
	if(flag==1) {
		sort(b,b+in+1);
		printf("Insertion Sort\n");
	}
	else if(flag==0) {
		printf("Heap Sort\n");
		sort(a,a+n);
		for(i=n-1;i>=0;i--) {
			if(a[i]!=b[i]) {
				break;
			}
		}	
		int t=i,max=-1,index;
		for(i=0;i<=t;i++) {
			if(b[i]>max) {
				max=b[i];
				index=i;
			}
		}
		int temp=b[t];
		b[t]=b[index];
		b[index]=temp;
		for(j=0;j<n;j++) {
			if(2*j+1>=t) break;
			if(2*j+2>=t) {
				if(b[2*j+1]>b[j]) {
					int t=b[j];
					b[j]=b[2*j+1];
					b[2*j+1]=t;
				}
				break;
			}
			int index,t;
			if(b[j]>b[j*2+1] && b[j]>b[2*j+2]) continue;
			else {
				index=(b[j*2+1]>b[j*2+2]?j*2+1:j*2+2);
				t=b[index];
				b[index]=b[j];
				b[j]=t;
			}	
		}
	}
	printf("%d",b[0]);
	for(i=1;i<n;i++) {
		printf(" %d",b[i]);
	}
	return 0;
}
