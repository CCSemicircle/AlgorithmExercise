#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN=601;

// 最大公约数GCM：欧几里得算法/辗转相除法，(a, b)和(b, a mod b)的最大公约数一致
int GCD(int a, int b){
    while(b){
        int temp=b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 最小公倍数LCM：a*b/最大公约数

int main(){
    int num[MAXN];
    int n;
    while(cin>>n && n){
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        sort(num,num+n);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(GCD(num[i],num[j]) == 1){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}
