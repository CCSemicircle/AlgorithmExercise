/**
设f(m, n)表示将m个苹果放到n个盘子中的方法数。
把问题分成两种情况:
(1) 盘子数n > 苹果数m ：则无论怎样放必然有n - m个空盘子，这些盘子都废掉了。实际上f(m , n) = f(m , m)
(2) 盘子数n <= 苹果数m: 这时候考虑到底是每个盘子都放苹果还是留至少一个空盘子。
若都放，则先每个盘子都预置一个苹果，还剩m-n个苹果放到n个盘子，即f(m-n, n)；
若留空盘子，至少留一个，则将m个苹果放到n-1个盘子中,即f(m , n-1) 。故而f(m,n) = f(m-n, n) + f(m , n-1)。
边界情况:
n = 1时， 只有一个盘子了，显然只能把所有的苹果都放在里面
m = 0时， 没有苹果了，那就不放了，不放本身也是一种方法。
(实际上是考虑到f(m-n, n)，若m=0时设置值为0,则当n = m时,不留空盘子策略f(m-n, n) = 0，这就不对了)
**/
#include<iostream>

using namespace std;

const int MAXN=11;

int dp[MAXN][MAXN];  // dp代表 i个盘子 j个苹果时最多的放法

int main(){
    int m,n;
    while(cin>>m>>n){
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                // 初始条件，只有一个盘子，或者没有苹果（不放）
                if(i == 1 || j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if(i > j){
                    // 盘子数大于苹果数时,一定会有 i-j个盘子空着
                    dp[i][j] = dp[j][j];
                }else{
                    // 盘子数小于等于苹果数时，分为留不留空盘子两种
                    // 不留空盘子时，每个盘子预置一个，再分配
                    // 留空盘子时，至少留一个空盘子，至于留2个及以上的会考虑在下一级里
                    dp[i][j] = dp[i][j-i] + dp[i-1][j];
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}