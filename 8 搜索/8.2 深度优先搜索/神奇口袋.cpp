#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN=21;
int n;  // 物品个数
int thing[MAXN];

// v代表剩余体积，position代表当前物品编号（避免往前寻找，重复计数）
// 此题不需要标记，因为同一个物品可以出现在多个方案中
int DFS(int v, int position){
    if(v == 0){
        return 1;
    }
    else if(v < 0){
        return 0;
    }
    int failure = 0;  // 记录上次失败的物品体积
    int cnt = 0;
    // 此循环为当前状态层的所有状态
    for(int i=position;i<n;i++){
        // 剪枝
        if(v < thing[i] || thing[i] == failure) continue;
        
        if(DFS(v-thing[i],i+1)){
            cnt += DFS(v-thing[i],i+1);
        }else{
            failure = thing[i];
        }
    }
    return cnt;
}

bool Compare(int x,int y){
    return x>y;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&thing[i]);
        }
        sort(thing,thing+n,Compare);
        cout<<DFS(40, 0)<<endl;
    }
    return 0;
}