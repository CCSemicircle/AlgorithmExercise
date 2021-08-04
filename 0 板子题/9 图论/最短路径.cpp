#include<iostream>

using namespace std;

const int MAXN=101;
const int MOD=100000;

int father[MAXN];
int dis[MAXN][MAXN];

// 此处不能使用快速幂，会导致中间结果错误
int FastExp(int a, int k){
    int ans=1;
    while(k--){
        ans = (ans*a)%MOD;
    }
    return ans;
}

void Init(int n){
    for(int i=0;i<n;i++){
        father[i] = i;
        for(int j=0;j<n;j++){
            dis[i][j] = -1;
        }
        dis[i][i] = 0;  // 小技巧，不在内循环中判断，缩短时间
    }
}

int Find(int x){
    if(father[x] != x){
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int a,int b,int n, int k){
    int x = Find(a);
    int y = Find(b);
    if(x!=y){
        // 分属不同集合是，如果出现新的边（执行Union操作），那么一定要更新两个集合内所有点间距离，因为新边肯定比之前距离长
        for(int i =0;i<n;i++){
            if(x == Find(i)){
                // a所属集合
                for(int j=0;j<n;j++){
                    if(y == Find(j)){
                        // b所属集合
                        int distance = FastExp(2,k);
                        dis[i][j] = dis[j][i] = (dis[i][a] + dis[b][j] + distance) % MOD;
                    }
                }
            }
        }
        // 注意先更新距离再合并
        father[y] = x;  // 不用考虑高度
    }
}



int main(){
    int n,m;
    while(cin>>n>>m){        
        Init(n);
        for(int i=0;i<m;i++){
            int from,to;
            cin>>from>>to;
            Union(from,to,n,i);
        }
        for(int i=1;i<n;i++){
            cout<<dis[0][i]<<endl;
        }
    }
    return 0;
}

