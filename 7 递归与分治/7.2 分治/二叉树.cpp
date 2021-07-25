#include<iostream>

using namespace std;

long long Function(long long m, long long n){
    if(m > n){
        return 0;
    }else{
        return Function(m*2,n)+Function(m*2+1, n)+1;
    }
}

int main(){
    long long m,n;
    while(cin>>m>>n){
        if(m==0 && n==0){
            break;
        }
        cout<<Function(m, n)<<endl;
    }
}