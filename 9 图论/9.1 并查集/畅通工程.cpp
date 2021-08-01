#include<iostream>

using namespace std;

const int MAXN=1000;

int father[MAXN];
int height[MAXN];

void init(int n){
    // 编号从1到N
    for(int i=1;i<=n;i++){
        father[i] = i;
        height[i] = 0;
    }
}

int Find(int x){
    if(father[x] != x){
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x,int y){
    x = Find(x);
    y = Find(y);
    if(x!=y){
        if(height[x] < height[y]){
            father[x] = y;
        }else if(height[x] > height[y]){
            father[y] = x;
        }else{
            father[y] = x;
            height[x]++;
        }
    }
}

int main(){
    int n,m;
    while(cin>>n>>m && n){
        init(n);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            Union(x,y);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(father[i]==i){
                // 找到有多少根节点，就有多少个连通分量
                cnt++;
            }
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}