#include<iostream>
#include<cstring>

using namespace std;

const int MAXN=10010;

int weight[MAXN];
int value[MAXN];
int k[MAXN];
int w[MAXN];  // 分组之后的体积数组 
int v[MAXN];  // 分组之后的价值数组 
int dp[MAXN];

int main(){
	int caseNumber;
	int n,m;
	cin>>caseNumber;
	while(caseNumber--){
		cin>>m>>n;
		for(int i=1;i<=n;i++){
			cin>>weight[i]>>value[i]>>k[i];
		}
		// 拆分成组 
		int cnt=1;
		for(int i=1;i<=n;i++){
			// 并非取二进制数的非0位，而是从0次幂，到1，2，3...次幂 
			for(int j= 1;j<=k[i];j<<1){
				w[cnt] = j*weight[i];
				v[cnt] = j*value[i];
				cnt++;
				k[i] -= j;
			}
			if(k[i] > 0){
				w[cnt] = k[i]*weight[i];
				v[cnt] = k[i]*value[i];
				cnt++;
			}
		}
		// 0-1背包
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=cnt;i++){
			for(int j=m;j>=w[i];j--){
				dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
			}
		} 
		cout<<dp[m]<<endl;
	}
	return 0;
}
