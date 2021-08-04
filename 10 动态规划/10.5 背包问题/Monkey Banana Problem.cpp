#include<iostream>
#include<cstring>

using namespace std;

const int MAXN=110;

int matrix[2*MAXN][MAXN];
int dp[2*MAXN][MAXN];

int main(){
    int caseNumber;
    int n;
    cin>>caseNumber;
    for(int t=1;t<=caseNumber;t++){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cin>>matrix[i][j];
                dp[i][j] = matrix[i][j];
            }
        }
        for(int i=n;i<2*n-1;i++){
            for(int j=0;j<=2*n-i-2;j++){
                cin>>matrix[i][j];
                dp[i][j] = matrix[i][j];
            }
        }
        // 下半部分三角形，从下往上推
        for(int i=2*n-3;i>=n-1;i--){  // 2*n-2 为最后一行，只有一个元素，可以直接从2*n-3开始
            // 注意边界条件，最左边和最右边
            for(int j=0;j<=2*n-i-2;j++){
                if(j==0){
                    dp[i][j] += dp[i+1][j];
                }else if(j == 2*n-i-2){
                    dp[i][j] += dp[i+1][j-1];
                }else{
                    dp[i][j] += max(dp[i+1][j],dp[i+1][j-1]);  // 下半部分是 j 和 j-1
                }
            }
        }
        // 上半部分三角形，也是从下往上推
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);  // 上半部分是 j 和 j+1
            }
        }
        printf("Case %d: %d\n",t,dp[0][0]);
    }
    return 0;
}
