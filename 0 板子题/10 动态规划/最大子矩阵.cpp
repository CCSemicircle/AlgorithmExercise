#include<iostream>
#include<climits>

using namespace std;

const int MAXN=101;
const int INF = INT_MIN;

int matrix[MAXN][MAXN];
int total[MAXN][MAXN];  // 存储列累计和的辅助矩阵
int arr[MAXN];
int dp[MAXN];

int MaxSubSequence(int n){
    dp[0] =arr[0];
    int maxSum = dp[0];
    for(int i=0;i<n;i++){
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
}

int MaxSubMatrix(int n){
    // 用第一行数据初始化
    int maxSum = INF;
    // 有点类似于选择排序的逻辑，找到以 i 行开始 j 行结尾的最大子矩阵
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            // k 表示列
            for(int k=0;k<n;k++){
                if(i == 0){
                    arr[k] = total[j][k];
                }else{
                    arr[k] = total[j][k] - total[i-1][k];
                }
            }
            maxSum = max(maxSum, MaxSubSequence(n));
        }
    }
    return maxSum;
}

int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
                // 初始化辅助矩阵
                if(i == 0){
                    total[i][j] = matrix[i][j];
                }else{
                    total[i][j] = total[i-1][j] + matrix[i][j];
                }
            }
        }
        cout<<MaxSubMatrix(n)<<endl;
    }
    return 0;
}