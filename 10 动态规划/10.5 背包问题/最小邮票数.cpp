#include<iostream>
#include<climits>

using namespace std;

const int MAXN=110;
const int INF=1e9;

int w[MAXN];
int dp[MAXN];

int main(){
    int n,m;
    // 把邮票总值视为容量，邮票面值视为物品体积，每个邮票的价值均视为1，此处求最小价值
    // dp代表凑成容量 j 时，所需的最小价值
    while(cin>>m>>n){
        for(int i=1;i<=n;i++){
            cin>>w[i];
        }
        // 保证取最小值的初始化
        // 其含义为：在加上当前邮票情况下能凑成这个总值，就把邮票数+1，加上当前邮票不能凑成的话其值肯定为INF
        /* 示例：
            dp[i][j]    0   1   2   3   4   5   6   7   8   9   10
            1           0   1   ∞   ∞   ∞   ∞   ∞   ∞   ∞   ∞   ∞
            1 3         0   1   ∞   1   2   ∞   ∞   ∞   ∞   ∞   ∞
            1 3 3       0   1   ∞   1   2   ∞   2   3   ∞   ∞   ∞
            1 3 3 3     0   1   ∞   1   2   ∞   2   ∞   ∞   3   4
            1 3 3 3 4   0   1   ∞   1   2   2   2   2   3   3   3  
        */
        for(int i=0;i<=m;i++){
            dp[i] = INF;  // 初始化为最大值，不能初始化为INT_MAX，因为INT_MAX+1溢出变成负数，会干扰计算结果
        }
        // 初始一个实际情况的边界条件，不能全部初始化为最大值，否则无法输出
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=w[i];j--){
                dp[j] = min(dp[j],dp[j-w[i]]+1);
            }
        }
        if(dp[m] == INF){
            cout<<0<<endl;
        }else{
            cout<<dp[m]<<endl;
        }
    }
    return 0;
}