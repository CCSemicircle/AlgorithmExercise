#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n,a;
    while(cin>>n>>a){
        int k=1e5;  // 初始化要为一个极大值
        for(int i=2;i<=n;i++){
            // 求所有小于n的因子的幂指数
            int j=i;
            int nFactors=0;  // 当前因子i的幂指数
            while(n/j > 0){
                nFactors += n/j;
                j *= i;
            }
            // 求 a 的因子的幂指数
            // 求a的因子一定要改变a，不然对于2 和 4 这种倍数因子就会重复计算，意味着此处其实是求质因子
            // 所以本题的实质是求 a^k 与 n! 两者质因子的幂指数的倍数关系
            int aFactors=0;
            while(a >= i && a%i == 0 ){
                aFactors++;
                a /= i;
            }
            
            if(aFactors != 0){
                // 如果i是a的因子，求此时最小 n的幂指数/a的幂指数 的值，即可以求得最大的k，且能够满足n! 可以被 a^k 整除
                if(k > nFactors/aFactors){
                    k = nFactors/aFactors;
                }
            }
        }
        cout<<k<<endl;
    }
    return 0;
}