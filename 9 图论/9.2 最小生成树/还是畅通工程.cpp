#include<iostream>
#include<algorithm>

using namespace std;

struct Edge{
    int from;
    int to;
    int weight;
    bool operator<(const Edge& e){
        return weight < e.weight;
    }
};

const int MAXN=100;

int father[MAXN];
int height[MAXN];
Edge edge[MAXN*MAXN];


void Init(int n){
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
    if(x != y){
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

int Kruskal(int n,int edgeNumber){
    Init(n);
    sort(edge,edge+edgeNumber);
    int sum=0;
    for(int i=0;i<edgeNumber;i++){
        if(Find(edge[i].from) != Find(edge[i].to)){
            sum += edge[i].weight;
            Union(edge[i].from,edge[i].to);
        }
    }
    int component=0;
    for(int i=1;i<=n;i++){
        if(father[i] == i){
            component++;
        }
    }
    if(component > 1){
        // 非连通图
        sum = -1;
    }
    return sum;
}

int main(){
    int n;
    while(cin>>n && n){
        int edgeNumber = n*(n-1)/2;
        for(int i=0;i<edgeNumber;i++){
            cin>>edge[i].from>>edge[i].to>>edge[i].weight;
        }
        int ans = Kruskal(n,edgeNumber);
        cout<<ans<<endl;
    }
    return 0;
}