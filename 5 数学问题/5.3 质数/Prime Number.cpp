#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

// 注意最大的k是10000，那么包含10000个素数的范围很大
const int MAXN = 10000001;

vector<int> primeNumber;
bool isPrime[MAXN];

void Init(){
    for(int i=0;i<MAXN;i++){
        isPrime[i]=true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    // 根据从小到大的因子关系，确定素数表，不再对每个数计算
    for(int i=2;i<MAXN;i++){
        // 先判断已经是否被标记为false
        if(!isPrime[i]){
            continue;
        }
        // 将素数的倍数全部标记为false
        primeNumber.push_back(i);
        // 用i乘大于i的数
        for(int j=i*i;j<MAXN;j+=i){
            isPrime[j]=false;
        }
    }
}

int main(){
    int k;
    Init();
    while(cin>>k){
        cout<<primeNumber[k-1]<<endl;
    }
    return 0;
}