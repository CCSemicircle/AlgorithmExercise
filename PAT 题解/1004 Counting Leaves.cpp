#include <iostream>
#include <vector>

using namespace std;

vector<int> node[100];
int cnt[100];
int maxDepth = -1;

void DFS(int pos, int depth) {
    if(node[pos].size() == 0) {
        cnt[depth]++;
        maxDepth = max(maxDepth, depth);
        return ;
    }
    int len = node[pos].size();
    for(int i = 0; i < len; i++)
        DFS(node[pos][i], depth + 1);
}
int main() {
    int n, m;
    while(cin>>n && n){
        cin>> m;
        for(int i = 0; i < m; i++) {
            int father, len;
            cin>>father>>len;
            for(int j = 0; j < len; j++) {
                int child;
                cin>>child;
                node[father].push_back(child);
            }
        }
        DFS(1, 0);
        for(int i = 0; i < maxDepth; i++)
            cout<<cnt[i]<<" ";
        cout<<cnt[maxDepth]<<endl;
    }
    return 0;
}