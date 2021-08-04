#include<iostream>

using namespace std;

const int MAXN=1000001;

long long arr[MAXN];
long long dp[MAXN];

long long MaxSubSeqSum(int n){
    dp[0] =arr[0];
    long long maxSum = dp[0];
    for(int i=0;i<n;i++){
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
}


int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<MaxSubSeqSum(n)<<endl;
    }
    return 0;
}