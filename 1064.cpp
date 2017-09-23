#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

vector<int> tree;
vector<int> nodes;
int N;

void buildTree(int root){
    static int index = 1;
    if(root > N) return;
    buildTree(root * 2);
    tree[root] = nodes[index++];
    buildTree(root * 2 + 1);
}

int main()
{
    cin >> N;
    nodes.resize(N+1);
    tree.resize(N+1);
    for(int i = 1; i <= N; i++){
        scanf("%d",&nodes[i]);
    }
    sort(nodes.begin(),nodes.end());
    buildTree(1);
    printf("%d",tree[1]);
    for(int i = 2; i <= N; i++)
        printf(" %d",tree[i]);
    cout << endl;
    return 0;
}
