#include<iostream>

using namespace std;

const int MAXN=10010;

int dp[MAXN];
int start[MAXN];
int arr[MAXN];

int main(){
    int n;
    cin>>n;
    int maxIndex = 0;  // 最大值的下标
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i] = arr[i];
        start[i] = arr[i];
    }
    for(int i=1;i<n;i++){
        if(dp[i] < dp[i-1]+arr[i]){
            start[i] = start[i-1];
            dp[i] = dp[i-1]+arr[i];
        }
        if(dp[maxIndex] < dp[i]){
            maxIndex = i;
        }
    }
    if(dp[maxIndex] < 0){
        printf("0 %d %d\n",arr[0],arr[n-1]);
    }else{
        printf("%d %d %d\n",dp[maxIndex],start[maxIndex],arr[maxIndex]);
    }
    return 0;
}