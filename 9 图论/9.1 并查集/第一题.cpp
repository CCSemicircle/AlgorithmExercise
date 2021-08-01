#include<iostream>
#include<cstring>

using namespace std;

const int MAXN=1000001;

int father[MAXN];
int height[MAXN];
int visit[MAXN];

void Init(){
    memset(visit,false,sizeof(visit));
    memset(father,0,sizeof(father));
    memset(height,0,sizeof(height));
}

int Find(int x){
    // 如果根结点的父结点设置为常数，注意不同情况返回值不同
    if(father[x] != 0){
        // 进行路径压缩，返回值为 father[x]
        father[x] = Find(father[x]);
        return father[x];
    }
    // 根结点的父结点不是本身，注意修改返回值
    return x;
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
    int i,j;
    Init();
    while(cin>>i>>j){
        visit[i] = true;
        visit[j] = true;
        Union(i,j);
    }
    int component=0;
    for(int i=0;i<MAXN;i++){
        if(!visit[i]){
            continue;
        }
        if(father[i] == 0){
            component++;
        }
    }
    cout<<component<<endl;
    return 0;
}