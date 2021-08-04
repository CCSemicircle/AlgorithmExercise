#include<iostream>
#include<cstring>

using namespace std;

const int MAXN=1010;

int w[MAXN];
int v[MAXN];
int dp[MAXN];

int main(){
    int n,m;  // n代表物品数，m代表背包容量
    while(cin>>m>>n){
        for(int i=1;i<=n;i++){
            cin>>w[i]>>v[i];
        }
        memset(dp,0,sizeof(dp));  // 初始化为0
        for(int i=1;i<=n;i++){
            for(int j=m;j>=w[i];j--){
                // 一定要考虑 j 是否大于 w[i]
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}