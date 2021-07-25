#include<iostream>
#include<cmath>

using namespace std;


const int MAXN=10001;

bool IsPrime(int x){
    int bound=sqrt(x);
    for(int i=2;i<=bound;i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    while(cin>>n){
        // 只判断个位数为1的数
        for(int i=11;i<n;i+=10){
            if(IsPrime(i)){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}