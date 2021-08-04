#include<iostream>
#include<cstring>

using namespace std;

const int MAXN=1001;

char s1[MAXN];
char s2[MAXN];
int dp[MAXN][MAXN];

int main(){
	// 从 1 开始输入方便处理边界条件，无需在循环中判断边界 
	while(scanf("%s %s",s1+1,s2+1)!=EOF){
		int n = strlen(s1+1);  // 注意从1开始才是字符串真实长度 
		int m = strlen(s2+1);
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				// 初始化边界条件 
				if(i == 0 || j ==0){
					dp[i][j]=0;
					continue;
				} 
				if(s1[i] == s2[j]){
					dp[i][j] = dp[i-1][j-1]+1;
				}else{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
} 
