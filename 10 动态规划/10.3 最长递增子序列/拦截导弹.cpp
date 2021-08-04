#include<iostream>

using namespace std;

const int MAXN=26;

int height[MAXN];
int dp[MAXN];

int main(){
    int k;
    while(cin>>k){
        for(int i=0;i<k;i++){
            cin>>height[i];
        }
        dp[0] = 1;
        int maxLength = dp[0];
        for(int i=0;i<k;i++){
            dp[i] = 1;
            // 注意起始编号和 “不高于” 的题目要求
            for(int j=i-1;j>=0;j--){
                if(height[i] <= height[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        cout<<maxLength<<endl;
    }
    return 0;
}