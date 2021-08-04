/**
因为2的次幂中包含奇数1，考虑以下两种情况：
1. N为奇数，dp[N] = dp[N-1];
2. N为偶数，继续考虑两种情况：
  2.1 N拆分出1（至少一个），f[N] = f[N-1];
  2.2 N不拆分1，那么每个和子都是2的倍数，均除2，f[N]不变，即得f[N] = f[N/2];
  因而，此时dp[N] = dp[N-1] + dp[N/2];
**/
#include<iostream>

using namespace std;

const int MAXN=1000010;
const int MOD=1000000000;

int dp[MAXN];

int main(){
    int n;
    dp[1]=1;
    while(cin>>n){
        for(int i=2;i<=n;i++){
            if(i%2 == 0){
                dp[i] = dp[i-1] + dp[i/2];
            }else{
                dp[i] = dp[i-1];
            }
            dp[i] %= MOD;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}