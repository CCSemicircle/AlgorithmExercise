#include<iostream>

using namespace std;

const int MAXN=510;
const int INF=1e9;

int w[MAXN];
int v[MAXN];
int dp[MAXN];

int main(){
	int E,F,n,m;
	int caseNumber;
	cin>>caseNumber;
	while(caseNumber--){
		cin>>E>>F;
		m = F-E;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>v[i]>>w[i];
		}
		// 初始化为极大值以求最小值 
		for(int i=0;i<=m;i++){
			dp[i]=INF;
		}
		// 初始化一个真实的边界条件 
		dp[0] = 0;
		for(int i=1;i<=n;i++){
			// 完全背包问题正序遍历 
			for(int j=w[i];j<=m;j++){
				dp[j] = min(dp[j], dp[j-w[i]]+v[i]);
			}
		}
		if(dp[m] == INF){
			printf("This is impossible.\n");
		}else{
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
		}
	}
	return 0;
}
