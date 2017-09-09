#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
const int sqrN = 316;
stack<int> s;
int block[sqrN];
int table[maxn];
void Pop(){
int elem;
if(s.empty())
cout << "Invalid" << endl;
else{
elem = s.top();
table[elem] --;
block[elem/sqrN] --;
s.pop();
cout << elem << endl;
}
}
void Push(){
int elem;
cin >> elem;
table[elem] ++;
block[elem/sqrN] ++;
s.push(elem);
}
void PeekMedian(){
if(s.empty())
cout << "Invalid" << endl;
else{
int sum_ = 0;
int idx = 0;
int len = s.size();
int mid = (len % 2 == 0) ? (len / 2) : ((len + 1) / 2);
while(sum_ + block[idx] < mid)
sum_ += block[idx++];
int num = idx * sqrN;
while(sum_ + table[num] < mid)
sum_ += table[num++];
printf("%d\n", num);
}
}
int main(){
int n;
cin >> n;
char op[15];
while(n--){
scanf("%s", op);
if(op[1] == 'o')
Pop();
else if(op[1] == 'u')
Push();
else if(op[1] == 'e')
PeekMedian();
}
return 0;
}
