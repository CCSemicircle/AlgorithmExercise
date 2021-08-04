#include<iostream>

using namespace std;

const int MAXN=110;

int matrix[MAXN][MAXN];
int dp[MAXN][MAXN];


int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			for(int j=0;j<=i;j++){
				cin>>matrix[i][j];
			}
		}
		// dp[i][j] 表示从下往上在(i,j)点的最大路径
		// 初始化边界条件 
		for(int i=0;i<n;i++){
			dp[n-1][i] = matrix[n-1][i];
		} 
		// 从下往上遍历 
		for(int i=n-2;i>=0;i--){
			for(int j=0;j<=i;j++){
				dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + matrix[i][j];
			} 
		}
		cout<<dp[0][0]<<endl;
	}
	return 0;
}
