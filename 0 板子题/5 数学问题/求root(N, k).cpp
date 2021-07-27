#include<iostream>

using namespace std;

int FastExp(long long a, long long b, int mod){
    long long ans=1;
    while(b){
        if(b%2 == 1){
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return ans;
}

int main(){
    long long x,y;
    int k;
    while(cin>>x>>y>>k){
        // 利用推导可得实际是求N % k-1
        int ans = FastExp(x, y, k-1);
        if(ans == 0){
            ans = k-1;
        }
        cout<<ans<<endl;
    }
}