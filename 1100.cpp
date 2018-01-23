#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	int n,i,j;
	string mars1[]={"tret","jan", "feb", "mar", 
	"apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	string mars2[]={" ","tam", "hel", "maa", "huh", "tou", "kes",
	 "hei", "elo", "syy", "lok", "mer", "jou"};
	scanf("%d",&n);
	getchar();
	while(n--) {
		string t;
		int temp;
		getline(cin,t);
		if(t[0]>='0'&&t[0]<='9') {
			temp=stoi(t);
			vector<int> mm;
			if(temp==0) {
				printf("tret\n");
				continue;
			}
			while(temp) {
				int a=temp%13;
				temp/=13;
				mm.push_back(a);
			}
			if(mm.size()==2) {
				if(mm[0]==0)
					cout<<mars2[mm[1]]<<endl;
				else 
					cout<<mars2[mm[1]]<<" "<<mars1[mm[0]]<<endl;
			}
			else if(mm.size()==1) {
				cout<<mars1[mm[0]]<<endl;
			}
		}
		else {
			if(t.size()>4) {
				string a=t.substr(0,3);
				string b=t.substr(4,t.size());
				for(i=1;i<13;i++) {
					if(a==mars2[i])
						break;
				}
				int a1=i;
				for(i=0;i<13;i++) {
					if(b==mars1[i])
						break;
				}
				int b1=i;
				printf("%d\n",a1*13+b1);
			}
			else {
				for(i=0;i<13;i++) {
					if(t==mars1[i]) {
						printf("%d\n",i);
						break;
					}
				}
				if(i==13) {
					for(i=1;i<13;i++) {
						if(t==mars2[i]) {
							printf("%d\n",i*13);
							break;
						}
					}
				}
			}
		}	
	}
	return 0;
} 
